#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>


//using namespace std;

int data = 123;
bool isDataReady = false;
std::mutex mymutex;
std::condition_variable c_var;
const auto number_of_iteration = 5;

void consumer()
{
    std::cout << std::endl << std::endl << "******* Consumer:  created *************" <<  std::endl;
    auto i=0;
    while(true)
    {
        
        std::cout << std::endl << std::endl << "Consumer: ------------- iteration num " << i+1 <<  std::endl;
        std::unique_lock<std::mutex> ul(mymutex);  //note we use unique_lock instead of lock_guard
        c_var.wait(ul, [](){return isDataReady;}); //the check is useful for avoiding spurious wake

        std::cout << "Consumer: I received the notification " <<  std::endl; //and wait function has locked the mutex, so I can change the data in shared memory

        int mydata = data; //get the data
        isDataReady = false;
        ul.unlock();

        //consume data outside the critical section
        std::cout << "Consumer: my data is " << mydata << std::endl;
        i++;
    }
    
}

void producer()
{
    std::cout << std::endl << std::endl << "********* Producer: created ***********" <<  std::endl;
    auto i=0;
    while(true)
    {
        
        std::cout << std::endl << std::endl << "Producer: ------------- iteration num " << i+1 << std::endl;
        //1. prepare the data 
        int dataProd = std::rand();
        std::cout << "Producer: my data is " << dataProd << std::endl;

        //2. pass the data in the shared memory
        {
            std::lock_guard <std::mutex> ul(mymutex);
            std::cout << "Producer: enter in critical section ..." << dataProd << std::endl;

            data = dataProd;
            isDataReady = true;
        }

        std::cout << "Producer: I'm abut to notify ... " << dataProd << std::endl;
        c_var.notify_one(); //Here I have only one thread, otherwise I caould call notify_all()
        std::cout << "Producer: I'm abut to sleep ... " << dataProd << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        i++;
    }
    
}

int main ()
{
    std::thread consumer_th (consumer);
    std::thread producer_th (producer);
    
    producer_th.join();
    consumer_th.join();
    
    std::cout << "main ending..." <<std::endl;
    
}


//g++ -std=c++11 -pthread -o cond_variables cond_variables.cpp