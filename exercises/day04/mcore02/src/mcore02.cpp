
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "mcore02.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>

#include<iostream>

// --------------------------------------------------------------------------------------------------------------------
// - all the rest
// --------------------------------------------------------------------------------------------------------------------


// std::array

#include<array>
#include<utility>

namespace mcore02 { namespace ex06 {

    struct T1
    {
        T1() = default;
        T1(size_t a, size_t b) : pa(a, b) {}
        void fill(size_t a, size_t b) { pa = {a, b}; }
        void print() const { std::cout << "T1 = (" << pa.first << ", " << pa.second << ")" << std::endl; }
    private:
        std::pair<size_t, size_t> pa {0, 0};
    };

    constexpr size_t numberof {8};

    void run()
    {
        std::array<T1, numberof> anarrayofT1 = {};

        size_t s = anarrayofT1.size();
        anarrayofT1.at(2).fill(1, 2);
        anarrayofT1[0] = {3, 4};

        anarrayofT1[0].print();
    }

}}

#include<string>
#include<vector>
#include<memory>
#include<map>

// range based llop

namespace mcore02::ex07 {


    void run()
    {

        // slide 1
        {
            std::vector<int> fibo {0, 1, 1, 2, 3, 5, 8, 13};
            std::vector<std::string> names {};
            for(const auto &a : fibo) {
                names.push_back("name = " + std::to_string(a)); 
            }
            for(const auto &na : names) {
                std::cout << na << std::endl; 
            }
        }

        // slide 2
        {
            std::vector<int> fibo {0, 1, 1, 2, 3, 5, 8, 13};
            std::vector<std::string> names {};
            for(auto a : fibo) {
                a++;
            }
            for(const auto &a : fibo) {
                names.push_back("name = " + std::to_string(a)); 
            }            
            for(const auto &na : names) {
                std::cout << na << std::endl; 
            }
        }

        // slide 3
        {

        }

    }



}

// constexpr

namespace mcore02::ex08 {

    constexpr unsigned int factorial(const unsigned int n)
    {
        return n > 1 ? n * factorial(n-1) : 1;
    }

    constexpr size_t f3 = factorial(3);
    constexpr size_t f4 = factorial(4);


    struct P3D {
        static constexpr double MAX {9.0};

        double const x_; double const y_; double const z_;
        constexpr P3D(const double x = 0, const double y = 0, const double z = 0) 
            : x_{x}, y_{y}, z_{z} {}
        constexpr double get_x() const {return x_;}
        constexpr double get_y() const {return y_;}
        constexpr double get_z() const {return z_;}
    };


    void run()
    {
        if(f4 > f3)
        {
            std::cout << "factorial(3) = " << f3 << std::endl;
        }

        constexpr P3D pd3 {1.0, 2.0, 20.0};

        auto x = pd3.get_x();


    }

}

// enum+constexpr

#include<bitset>
namespace mcore02::ex09 {

template<typename E> 	// // C++14 [Meyers, pag. 73]
constexpr auto toUType(E enumerator) noexcept {
	return static_cast<std::underlying_type_t<E>>(enumerator);
}



template<typename E, E max>
    struct eMap {
        static_assert(toUType(max) < (8*sizeof(unsigned long long)), "size error");
        std::bitset<toUType(max)+1> mapp;
        constexpr eMap(const std::initializer_list<E> &li) {
            unsigned long long m = 0;
            for(auto &e : li) m |= (static_cast<unsigned long long>(1) << toUType(e)); 
            mapp = m;
        }        
        constexpr bool available(E e) const { return mapp[toUType(e)]; }        
    }; 

enum class Led : std::uint8_t { red = 0, green = 1, blue = 2, white = 63, max = white };

constexpr eMap<Led, Led::max> theLEDs {Led::red, Led::blue}; 

    void dosomething()
    {
        volatile int a {0};
        std::cout << "a = " << a << std::endl;
    }

    void doit()
    {
        volatile int b {1};
        std::cout << "b = " << b << std::endl;
    }

    void run()
    {
        if(theLEDs.available(Led::green)) {	// resolved at compile time.
            dosomething();		// on armclang compiler with 0 optimization …
        }				// no code is generated.

        if(theLEDs.available(Led::red)) {	// resolved at compile time.
            doit();			// on armclang compiler with 0 optimization …
        }	
    }

}

// override
namespace mcore02::ex10 {

    void run()
    {


    }

}

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




