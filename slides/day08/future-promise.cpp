#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
 
void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    std::this_thread::sleep_for(std::chrono::seconds(3)); //simulate to do some work
    std::cout << "I'm in accumulate... I'm about to set the result in promise.." <<std::endl;
    accumulate_promise.set_value(sum);  // Notify future
}
 
void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    barrier.set_value();
}


void square(std::future<int> f)
{
    std::cout << "I'm in square... I'm wainting the input.." <<std::endl;
    int x = f.get();
    std::cout << "result in Square is " << x*x << std::endl;
}
 
int main()
{
     std::cout << "Main is starting" << std::endl;
    // ---- 1) Demonstrate using promise<int> to get the result from a thread.
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    std::thread work_thread(accumulate, numbers.begin(), numbers.end(),
                            std::move(accumulate_promise));


    // ---- 2) Demonstrate using promise<int> to pass a value to the thread in the future.
    std::promise<int> square_promise;
    std::future<int> square_future = square_promise.get_future();
    std::thread square_thread (square, std::move(square_future));


    //future::get() will wait until the future has a valid result and retrieves it.
    //Calling wait() before get() is not needed
    std::cout << "main: I'm waiting the accumulate result .... " <<std::endl;
    auto accumulate_res =  accumulate_future.get();
    std::cout << "main: accumulate result is " << accumulate_res <<std::endl <<std::endl;
 
    work_thread.join();  // wait for thread completion
    
    std::cout << "main: I'm going to pass a value (7) to square_thread" << std::endl;
    square_promise.set_value(7);
    
    square_thread.join();
    
    std::cout << "main is ending" << std::endl;
}

//g++ -std=c++11 -pthread -o future-promise future-promise.cpp