
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "modernprinter.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <memory>
#include <iostream>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------


      
struct modern::printer::Client::Impl
{
    bool _initted {false};    
    Config _config {}; 
    
    Impl() = default;

    bool initialise(const Config &config)
    {
        if(true == _initted)
        {
            return false;
        } 
        
        _config = config;        
        _initted = true;   

        return _initted;
    }
    
    
    bool send(const std::string &str)
    {
        auto r {false};

        if(false == _initted)
        {
            return r;
        }

        
        
        // this implementation calls printer::Server. 
        // others can send the string over a socket or to another thread or to a shared memory area 

        r = modern::printer::theServer::getInstance().receive(std::string(_config.name) + ": " + str);
//        r = _config.srv->receive("from " + _config.name + ": " + str);
        
        return r;           
    }
    
};
    
    
struct modern::printer::theServer::Impl
{
    bool _initted {false};    
    Config _config {};

    Impl() = default;
            
    bool initialise(const Config &config)
    {
        if(true == _initted)
        {
            return false;
        } 

        _config = config;        
        _initted = true;   

        return _initted;
    }
    
    
    bool receive(const std::string &str)
    {
        bool r {false};

        if(false == _initted)
        {
            return r;
        }

        // do something
               
        
        std::cout << _config.name << ": "  << str << std::endl;
        r =  true;

        return r;           
    }
    
};

    



// --------------------------------------------------------------------------------------------------------------------
// - the class
// --------------------------------------------------------------------------------------------------------------------



namespace modern::printer {    

    Client::Client() : pImpl(std::make_unique<Impl>()) {}
    Client::~Client() = default;


    bool Client::initialise(const Config &config)
    {
        return pImpl->initialise(config);
    }

    bool Client::send(const std::string &str)
    {
        return pImpl->send(str);
    }     
    
}

namespace modern::printer {

    theServer& theServer::getInstance()
    {
        static theServer instance;
        return instance;
    }

    theServer::theServer()
    {
        pImpl = std::make_unique<Impl>();
    }  
                    
    bool theServer::initialise(const Config &config)
    {
        return pImpl->initialise(config);
    }

    bool theServer::receive(const std::string &str)
    {
        return pImpl->receive(str);
    }

}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


