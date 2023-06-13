
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __PRINTERCLIENT_H_
#define __PRINTERCLIENT_H_


#include "printerIF.h"
#include <string>

namespace printer {
    
    class printerClient : public IFclient
    {
    public:
            
        struct Config
        {        
            IFserver * srv;
            std::string name;    
            Config() : srv(NULL), name("") {}
            Config(IFserver *s, std::string n) : srv(s), name(n) {}
        };   

        printerClient(); 
        ~printerClient();                          
                
        bool initialise(const Config &config);   
        bool send(const std::string &str);        
        
    private:
        printerClient(const printerClient&);            
        printerClient& operator=(const printerClient&); 

        struct Impl;
        Impl* pImpl;    
    }; 

    
}   // namespace printer {
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


