
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "printerServer.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include<iostream>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------



namespace printer {
    
    
    struct printerServer::Impl
    {

        bool _initted;    
        Config _config;

        Impl() 
        {
            _initted = false;
        };
                
        bool initialise(const Config &config)
        {
            if(true == _initted)
            {
                return false;;
            } 
            
            _config = config;
            if(_config.name == "")
            {
                _config.name = "Server";                       
            }
            _initted = true;            
            return true;
        }
        
      
        bool receive(const std::string &str)
        {
            if(false == _initted)
            {
                return false;
            }
            // do something
            
            std::cout << _config.name << ": "  << str << std::endl;
            
            return true;           
        }
        
    };
    
    
}


// --------------------------------------------------------------------------------------------------------------------
// - the class
// --------------------------------------------------------------------------------------------------------------------



namespace printer {    

    printerServer::printerServer()
    {
        pImpl = new Impl;
    }  
        
    printerServer::~printerServer() 
    { 
        delete pImpl;
    }
            
    bool printerServer::initialise(const Config &config)
    {
        return pImpl->initialise(config);
    }

    bool printerServer::receive(const std::string &str)
    {
        return pImpl->receive(str);
    }      
    
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


