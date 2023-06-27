
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __MODERNPIMPL_H_
#define __MODERNPIMPL_H_

#include <string>
#include <memory>



namespace modern::pimpl::v00 {

    class Widget { 
    public:
        Widget();
        
        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::unique_ptr<Impl> pImpl;    // and pointer to it  
    }; 

}   
    

namespace modern::pimpl::v01 {

    // {copiable, moveable} = {false, false}
    // ruleofzero = false. but needed.
    class Widget { 
    public:
        Widget();
        ~Widget();

        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::unique_ptr<Impl> pImpl;    // and pointer to it  
    }; 
      
}      


namespace modern::pimpl::v02 {

    // {copiable, moveable} = {false, true}
    // ruleofzero = false. but needed.
    class Widget { 
    public:
        Widget();
        ~Widget();

        Widget(Widget&& rhs);               // move constructor
        Widget& operator=(Widget&& rhs);    // move assignment
        
        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::unique_ptr<Impl> pImpl;    // and pointer to it  
    }; 
      
}      



namespace modern::pimpl::v03 {

    // {copiable, moveable} = {true, true}
    // ruleoffive = true.
    class Widget { 
    public:
        Widget();
        ~Widget();

        Widget(const Widget& rhs);              // copy constructor
        Widget& operator=(const Widget& rhs);   // copy assignment

        Widget(Widget&& rhs);                   // move constructor
        Widget& operator=(Widget&& rhs);        // move assignment
        
        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::unique_ptr<Impl> pImpl;    // and pointer to it  
    }; 
      
}     


namespace modern::pimpl::v04 {

    // better use = delete to tell that we dont have a property. for example
    // {copiable, moveable} = {false, false}
    // ruleoffive = true.
    class Widget { 
    public:
        Widget();
        ~Widget();

        Widget(const Widget& rhs) = delete;
        Widget& operator=(const Widget& rhs) = delete;

        Widget(Widget&& rhs) = delete;
        Widget& operator=(Widget&& rhs) = delete;
        
        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::unique_ptr<Impl> pImpl;    // and pointer to it  
    }; 
      
}     

namespace modern::pimpl::v05 {


    // {copiable, moveable} = {true, true}
    // ruleoffive = true.
    class Widget { 
    public:
        Widget();

        
        void doit();

    private:
        struct Impl;                    // use smart pointer
        std::shared_ptr<Impl> pImpl;    // and pointer to it  
    }; 
      
}  

namespace modern::pimpl::singleton {

    // the Scott Meyers' singleton plus others:
    // - Item 26: Limiting the number of objects of a class, Scott Meyers, More Effective C++, 1996
    // - Item 22: When using the Pimpl Idiom, define special member functions in the implementation file,
    //   Scott Meyers, Effective Modern C++, ?
    // - Modern C++ Design: Generic Programming and Design Patterns Applied, By Andrei Alexandrescu, chapter 6.
    // - https://www.modernescpp.com/index.php/creational-patterns-singleton


    // i explicitely say that it is non-copiable and non-moveable
    // but also if i don't say it ... nothing changes in normal usage
    #define EXPLICITELY_NON_COPIABLE_MOVABLE

    // it solves:
    // - Static Initialization Order Fiasco 
    // - multithread access because of https://en.cppreference.com/w/cpp/language/storage_duration#Static_local_variables
    //   If multiple threads attempt to initialize the same static local variable concurrently, 
    //   the initialization occurs exactly once.
    
    class theOne
    {
        theOne();
        struct Impl;
        std::unique_ptr<Impl> pImpl;    
        ~theOne() = default; // possible because the dtor is used inside getInstance() after Impl definition   
    public:
        static theOne& getInstance();   
                                      
        void doit();   

#if defined(EXPLICITELY_NON_COPIABLE_MOVABLE)
        theOne(const theOne&) = delete;               // non copyable
        theOne& operator=(const theOne&) = delete;    // non copyable
        theOne(theOne&&) = delete;                    // non moveable
        theOne& operator=(theOne&&) = delete;         // non moveable                        
#endif

    };     


}

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


