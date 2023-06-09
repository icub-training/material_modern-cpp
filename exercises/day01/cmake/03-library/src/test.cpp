
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "test/test.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include<iostream>



// --------------------------------------------------------------------------------------------------------------------
// - all the rest
// --------------------------------------------------------------------------------------------------------------------

namespace d01 { namespace test {
 
    auto ncalls {0};
    void say(const std::string &str)
    { 
        ncalls ++;
        std::cout << "test lib: -> " << str << ", called " << std::to_string(ncalls) << " times" << std::endl;
    }  

    
}} // namespace d01::test


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




