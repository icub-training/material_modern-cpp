#include <memory>
#include <iostream>
#include <concepts>

struct Point {
    double X{0.0};
    double Y{0.0};
    Point(double _x, double _y): X(_x), Y(_y) {};
};

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
        //std::cout<<"The result is "<<result;

        // TODO try to invoke the functions using
        // the three couple of arguments
    }

    {
        // TODO write an "is_incrementable" concept
        // and use it
    }

    return 0;

}