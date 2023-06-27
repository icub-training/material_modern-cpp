// Copyright (C) Fondazione Istituto Italiano di Tecnologia (IIT)
// All Rights Reserved.

//author Valentina Gaggero <valentina.gaggero@iit.it>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <utility>

static int numCopiesMade = 0;
static int numMovedObj=0;


class BigObject
{
    enum { DataSize = 100000 };
public:

    BigObject()
        : data{new int[DataSize]}
    {
        std::cout << "BigObject constructor" << std::endl;
        std::generate(data, data + DataSize, rand);
    }

    ~BigObject()
    {
        std::cout << "BigObject deconstructor" << std::endl;;
        if(data!=nullptr)
            delete[] data;
   
    }

    BigObject(const BigObject &other)
        : data{new int[DataSize]}
    {
        std::cout << "BigObject copy constructor" << std::endl;
        numCopiesMade++;
        std::copy(other.data, other.data + DataSize, data);
    }

   

    BigObject& operator=(const BigObject &other)
    {
        std::cout << "BigObject copy-assignment operator" << std::endl;
        // copy+swap idiom, exception safe
        BigObject copy(other);
        using std::swap;
        swap(copy.data, data);
        return *this;
    }

    //insert here the move constructor

    //insert here the move-assignment object


   void setNewValueAtIndex(int index, int newvalue)
   {
        if(index<DataSize)
            data[index] = newvalue;
   }

private:
    int *data;

};

class ContainerOfObject
{
public:
    void addObject(BigObject &obj)
    {
        myvec.push_back(obj);
    }

   //Implement here the addObject using the move semantic

    int size(void)
    {return myvec.size();}


private:
    std::vector<BigObject> myvec;

};

BigObject createObject()
{
    BigObject myobj;
    myobj.setNewValueAtIndex(1, 100);
    return myobj;
}



int main()
{
    BigObject obj1 = createObject();
    //1) check if the RVO optimization has been applied.
    if(numMovedObj == 0)
    {
        std::cout << "RVO optimization has been applied!!!!"<< std::endl<< std::endl;
    }
    else
    {
        std::cout << "NO RVO optimization has been applied!!!!"<< std::endl<< std::endl;
    }
   
    ContainerOfObject container;
    std::cout << "INIT: number of copies = " << numCopiesMade << ". Number of moves = "<< numMovedObj << ".  The container has " << container.size() << " elements." << std::endl<< std::endl;

    container.addObject(obj1);
    std::cout << "FIRST: number of copies = " << numCopiesMade << ". Number of moves = "<< numMovedObj << ".  The container has " << container.size() << " elements." << std::endl<< std::endl;

    container.addObject(std::move(obj1));
    std::cout << "SECOND: number of copies = " << numCopiesMade << ". Number of moves = "<< numMovedObj << ".  The container has " << container.size() << " elements." << std::endl<< std::endl;

    obj1.setNewValueAtIndex(2, 33);

    BigObject obj2= BigObject();

    #warning question 6: put here the code
    //QUESTION 6: create obj3 from a temporary BigObject. Here are possible 2 solutions. Can you find both??    


    #warning question 7: put here the code
    //QUESTION 7: add 10 BigObject to the container in order to avoid copies.

}
