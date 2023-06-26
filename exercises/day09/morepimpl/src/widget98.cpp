
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "widget98.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------


      
struct cpp98::pimpl::Widget::Impl
{
    std::string _name;;

    Impl()
    {
        _name = "hello";
    }

    void doit()
    {
        std::cout << _name << std::endl;
    }  
};
    

namespace cpp98::pimpl {    

    Widget::Widget() // allocate data members for
    : pImpl(new Impl) // this Widget object
    {}

    Widget::~Widget() // destroy data members for
    { delete pImpl; } // this object

    void Widget::doit()
    {
        pImpl->doit();
    }
    
}



// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


