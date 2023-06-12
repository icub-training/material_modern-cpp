
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __PRINTERSERVER_H_
#define __PRINTERSERVER_H_


#include <string>

#include "printerIF.h"

namespace printer {

    class printerServer: public IFserver
    {
    public:
            
        struct Config
        {            
            std::string name;
            Config() : name("") {}
            Config(const std::string n) : name(n) {}
        };   

        printerServer(); 
        ~printerServer();                          
                
        bool initialise(const Config &config);   
        bool receive(const std::string &str);        
        
    private:
        printerServer(const printerServer&);            
        printerServer& operator=(const printerServer&); 

        struct Impl;
        Impl* pImpl;    
    }; 

    
}   // namespace printer {
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


