
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "modernpimpl.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <memory>
#include <iostream>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------

// - v00

struct modern::pimpl::v00::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};
    

namespace modern::pimpl::v00 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_unique<Impl>())   // std::unique_ptr
    {}                                  // via std::make_unique


    void Widget::doit()
    {
        pImpl->doit();
    }
    
}

// - v01

struct modern::pimpl::v01::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};
    

namespace modern::pimpl::v01 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_unique<Impl>())   // std::unique_ptr
    {}                                  // via std::make_unique

    Widget::~Widget() = default;

    void Widget::doit()
    {
        pImpl->doit();
    }
    
}

// - v02

struct modern::pimpl::v02::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};

namespace modern::pimpl::v02 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_unique<Impl>())   // std::unique_ptr
    {}                                  // via std::make_unique

    Widget::~Widget() = default;

    Widget::Widget(Widget&& rhs) = default;             // definitions
    Widget& Widget::operator=(Widget&& rhs) = default;  

    void Widget::doit()
    {
        pImpl->doit();
    }
    
}

// - v03


struct modern::pimpl::v03::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};

namespace modern::pimpl::v03 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_unique<Impl>())   // std::unique_ptr
    {}                                  // via std::make_unique

    Widget::~Widget() = default;

    Widget::Widget(Widget&& rhs) = default;             // definitions
    Widget& Widget::operator=(Widget&& rhs) = default;  // ... default is fine

    Widget::Widget(const Widget& rhs)                   // copy ctor
        : pImpl(std::make_unique<Impl>(*rhs.pImpl))     // cannot be default
    {}

    Widget& Widget::operator=(const Widget& rhs)        // copy operator=
    {                                                   // cannot be default
        *pImpl = *rhs.pImpl;
        return *this;
    }

    void Widget::doit()
    {
        pImpl->doit();
    }
    
}


// - v04


struct modern::pimpl::v04::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};

namespace modern::pimpl::v04 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_unique<Impl>())   // std::unique_ptr
    {}                                  // via std::make_unique

    Widget::~Widget() = default;

    void Widget::doit()
    {
        pImpl->doit();
    }
    
}

// - v05


struct modern::pimpl::v05::Widget::Impl
{
    std::string _name {"hello"};

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};

namespace modern::pimpl::v05 {    

    Widget::Widget()                    // allocate data members for
    : pImpl(std::make_shared<Impl>())   // std::shared_ptr
    {}                                  // via std::make_shared


    void Widget::doit()
    {
        pImpl->doit();
    }
    
}


// singleton

struct modern::pimpl::singleton::theOne::Impl
{
    std::string _name {"theOne"};

    void doit()
    {
        std::cout <<_name << std::endl;     
    }

    // if Impl() allocates or gets HW resources, then you can
    // use a init() / deinit() pair accessible to the public API
    // it is wise to call a deinit() in the ~Impl() if not deinitted yet.
    
};


namespace modern::pimpl::singleton {

    theOne& theOne::getInstance()
    {
        static theOne instance;
        return instance;
    }

//    theOne::~theOne() = default; // i can move it in the declation of the class

    theOne::theOne() : pImpl(std::make_unique<Impl>()) {};
                   
    void theOne::doit()
    {
        pImpl->doit();
    }

}

// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


