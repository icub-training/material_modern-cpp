#include <memory>
#include <iostream>
#include <concepts>
#include <ranges>
#include <algorithm>

template <typename T>
T add (T a, T b) requires std::integral<T>{
    return a+b;
}


int main(int argc, char *argv[])
{
    {
        char a_char{10};
        char b_char(10);

        int  a_int{10};
        int  b_int{20};

        double a_double{10};
        double b_double{10};

        // auto result = add(...,...);
        //std::cout<<"The result is "<<result<<std::endl;

        // TODO try to invoke the functions using
        // the three couple of arguments
    }

    {
        // TODO write an "is_incrementable" concept
        // and use it
    }

    {
        // TODO generate a series of numbers from 0 to 20
        // and print it only the even. You must use views
    }

    return 0;

}
