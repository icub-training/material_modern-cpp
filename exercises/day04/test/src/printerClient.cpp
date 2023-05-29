
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "printerClient.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include "printerServer.h"

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------



namespace printer {
    
    
    struct printerClient::Impl
    {
        bool _initted;    
        Config _config; 
        
        Impl() 
        {
            _initted =  false;
            _config.srv = NULL;       
        }
                
        bool initialise(const Config &config)
        {
            if(true == _initted)
            {
                return false;;
            } 

            if(NULL == config.srv)
            {
                return false;
            }
            
            _config = config;
            if(_config.name == "")
            {
                _config.name = "Client";                       
            }            
            _initted = true;   

            return true;
        }
        
        
        bool send(const std::string &str)
        {
            if(false == _initted)
            {
                return false;
            }

            bool r = false;
            
            // this implementation calls printerServer. 
            // others can send the string over a socket or to another thread or to a shared memory area 

            r = _config.srv->receive("from " + _config.name + ": " + str);
            
            return r;           
        }
        
    };
    
    
}


// --------------------------------------------------------------------------------------------------------------------
// - the class
// --------------------------------------------------------------------------------------------------------------------



namespace printer {    

    printerClient::printerClient()
    {
        pImpl = new Impl;
    }  
        
    printerClient::~printerClient() 
    { 
        delete pImpl;
    }
            
    bool printerClient::initialise(const Config &config)
    {
        return pImpl->initialise(config);
    }

    bool printerClient::send(const std::string &str)
    {
        return pImpl->send(str);
    }     
    
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


