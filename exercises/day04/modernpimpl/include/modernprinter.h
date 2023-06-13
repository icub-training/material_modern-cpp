
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __MODERNPRINTER_H_
#define __MODERNPRINTER_H_

#include <string>
#include <memory>

namespace modern::printer {
    
    class Client
    {
    public:
           
        struct Config
        {        
            static constexpr const char *defaultname {"Client"};     
            const char * name {defaultname};    
            constexpr Config() = default;
            constexpr Config(const char *n) : name((nullptr != n) ? n : defaultname) {}
        };   

        Client();                        
        ~Client(); 
                
        bool initialise(const Config &config);   
        bool send(const std::string &str);   

        Client(const Client&) = delete;               // non copyable
        Client& operator=(const Client&) = delete;    // non copyable
        Client(Client&&) = delete;                    // non moveable
        Client& operator=(Client&&) = delete;         // non moveable                
        
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;  
    }; 


    class theServer
    {
    public:
        static theServer& getInstance();   

        struct Config
        {   
            static constexpr const char *defaultname {"theServer"};     
            const char * name {defaultname};    
            constexpr Config() = default;
            constexpr Config(const char *n) : name((nullptr != n) ? n : defaultname) {}
        };   
                                      
        bool initialise(const Config &config);   
        bool receive(const std::string &str);   

        theServer(const theServer&) = delete;               // non copyable
        theServer& operator=(const theServer&) = delete;    // non copyable
        theServer(theServer&&) = delete;                    // non moveable
        theServer& operator=(theServer&&) = delete;         // non moveable                
        
    private:
        theServer();
    private:
        struct Impl;
        std::unique_ptr<Impl> pImpl;  
    }; 
    
}   
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


