
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "mcore01.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>

#include<iostream>

// --------------------------------------------------------------------------------------------------------------------
// - all the rest
// --------------------------------------------------------------------------------------------------------------------


// nullptr

namespace mcore01 { namespace ex01 {

    void f(int a);
    void f(char *a);


    void run()
    {
        f(0);  	        // calls f(int a) 
    //    f(NULL);  	    // calls f(int a): it is not what we wanted
        f(nullptr);  	// calls f(char *a) 
    }


    void f(int a)
    {
        std::cout << "called f(int a)" << std::endl;    
    }

    void f(char *a)
    {
        std::cout << "called f(char *a)" << std::endl;    
    }

}}

#include<string>
#include<vector>
#include<memory>
#include<map>

// auto

namespace mcore01::ex02 {


    // slide 3
    auto add(const int a, const int b) -> int { return a+b; }  	// C++11
    auto multiply(const int a, const int b) { return a*b; }	// C++14


    void run()
    {
        auto something {0};
        something ++;
        std::cout << "something has value: " << something << std::endl;

        // slide 1
        {
            auto i = 42; // int
            auto d = 42.5; // double
            auto s = "text"; // char const *
            auto v = { 1, 2, 3 }; // std::initializer_list<int>
        }

        // slide 1 extra
        {
            auto v = { 1, 2, 3 }; // std::initializer_list<int>        }    
            auto s1 = std::string {"text"}; // std::string
            auto v1 = std::vector<int> { 1, 2, 3 }; // std::vector<int>


            const char * ccc = s1.c_str();
            // ccc = s.c_str();

            size_t size = v1.size();
            size_t sizemaybe = v.size();
            v1.push_back(3);
            // v.push_back(2);
        }

        // slide 2
        {
            auto b = new char[10] { 0 }; // char*
            auto bb = new char[3] { 1, 2, 3 }; // char*
            auto s1 = std::string {"text"}; // std::string
            auto v1 = std::vector<int> { 1, 2, 3 }; // std::vector<int>
            auto p = std::make_shared<int>(42); // std::shared_ptr<int>
        }

        // slide 3
        {


            auto x = multiply(3, 2);


        }

        // slide 4
        {
            auto half = [](const double v) { return v/2.0; };
            auto result = half(8.0); 
        }

        // slide 5
        {
            auto half = [](const auto a) { return a/2; };
            constexpr double ninepointzero = 9.0;
            constexpr int eleven = 11;  
            auto result1 = half(ninepointzero);         	// it is 4.5 (double)
            auto result2 = half(eleven);            	    // it is 5 (int)
            auto x = result2;
            x = x;
        }


        // slide 6
        {

            auto v = std::vector<int>{ 1, 2, 3 };
            int size1 = v.size(); 	   // actually size() returns size_t …
            auto size2 = v.size(); // correct type size_t

        }

        // slide 7
        {
            auto v = std::vector<int>{ 1, 2, 3 };
            int size1 = v.size(); 	   // actually size() returns size_t …
            auto size2 = v.size(); // correct type size_t
        }

        // slide 8
        {

            std::map<int, std::string> m; // given this map …
            // we just want to iterate
            for (auto it = m.cbegin(); it != m.cend(); ++it)
            { /*...*/ }

            // we don’t care about the type of the iterator it 
            for(std::map<int,std::string>::const_iterator it = m.cbegin();
            it != m.cend(); ++it)
            { /*...*/ }

        }
    }



}

// type aliases

namespace mcore01::ex03 {

    using byte = unsigned char;
    using array10b_t = byte[10];
    using fpWorker = void (*)(void);
    void dosomething() 
    { 
        static array10b_t data = {0}; 
        data[0]++; 
        }
    void caller(fpWorker f) { f(); }
    void f1() { caller(dosomething); }

    typedef void (*FP0)(int &, const std::string&); // typedef

    // same meaning as above
    using FP1 = void (*)(int &, const std::string&); // alias declaration

    void ff(int &a, const std::string& s)
    {
        if(false == s.empty())
        {
            a++;
        }
    }

    void run()
    {

        f1();
        f1();

        FP1 fptr = ff;

        int a = 3;
        fptr(a, "");

        a = a;

        

    }

}

// initializer list

namespace mcore01::ex04 {

   template <class T>
    struct S {
        std::vector<T> v;
        S(std::initializer_list<T> l) : v(l) {  std::cout << "size = " << l.size();    }
        void append(std::initializer_list<T> l) { v.insert(v.end(), l.begin(), l.end()); }
    };


    size_t afun(const std::initializer_list<int> &l)
    {
        static size_t s {0};
        s = l.size();
        return s;
    }
    
    void run()
    {

        // slide 1
        {
        //    void afun(const std::initializer_list<int> &l); 
            auto ilis = { 10, 20, 30 };  // the type of ilis is initializer_list<int>
            auto ss = afun(ilis); 
            auto ilistr = { "hello", "world" } ;
        }


        // slide 2
        {
            std::array<int, 3> a3 = {1, 2, 3};  
            std::map<int, std::string> mm1 = { {1, "one"}, {2, "two"} };
            std::map<int, std::string> mm2 { {3, "three"}, {4, "four"} };

        }

        // slide 4
        {
            S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
            s.append({6, 7, 8}); // list-initialization in function call
        }


    }




}

// uniform initialization
namespace mcore01::ex05 {


    void run()
    {

        // slide 2
        {
            int i { 42 }; double d { 1.2 };
            int arr1[3] { 1, 2, 3 };  int* arr2 = new int[3]{ 1, 2, 3 };

            std::vector<int> v { 1, 2, 3 };
            std::vector<int> v1 {};
            std::map<int, std::string> m { {1, "one"}, { 2, "two" } }; 

            int arr[] = {3, 9, 27, 81};
            std::vector<int> vec98 (arr, arr + sizeof(arr) / sizeof(arr[0]) );

        }

        // slide 3
        {
            class FAQ {
                std::string question {"*"}; 
                int answer {42}; 
            public:
                FAQ() = default;
                FAQ(const std::string &q, int a) : question(q), answer(a) {}
                void print() const { std::cout << "the answer is: " << answer << ". the question was: " << question << std::endl; }
            }; 

            FAQ f0{};
	        FAQ f2{ "what?", 42};
            f2.print();

        }

        // slide 4
        {
            struct fee { 
                std::array<int, 2> a {0, 0}; 
                fee() = default;
                fee(int v1, int v2 = 1) : a{v1, v2} {} // useless
                fee(std::initializer_list<int> l) 
                { 
                    if(l.size() == 2)
                    { 
                        auto a {l.size()};
                        a++;
                    } 
                }
            };

            fee f { 1, 2 }; // calls constructor with initializer_list<int>;


        
        }


    }

}

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




