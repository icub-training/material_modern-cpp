
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "printerTest.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include<iostream>


#include "printerServer.h"
#include "printerClient.h"

#include <vector>

// --------------------------------------------------------------------------------------------------------------------
// - the code
// --------------------------------------------------------------------------------------------------------------------

namespace printer { namespace test {

    std::vector<std::string> strings;
    #if 0
    // it is not c++98    
    std::vector<std::string> strings 
    {
    "hello",
    "world",
    "of",
    "modern",
    "c++"                               
    };
    #endif

    bool get(std::vector<std::string> &pattern)
    {
        pattern = getpattern();
        return true;
    }

    std::vector<std::string> & getpattern()
    {
        if(strings.empty())
        {
            strings.push_back("hello");
            strings.push_back("world");
            strings.push_back("of");
            strings.push_back("modern");
            strings.push_back("C++");
        } 
        return strings;      
    }

    bool print(const std::vector<std::string>& ss)
    {
        std::cout << "The pattern is:" << std::endl;
        for(size_t i=0; i<ss.size(); i++)
        {
            std::cout << ss[i] << std::endl;   
        }  
        std::cout << "..." << std::endl;

        return true;
    }

    IFclient * obtain(IFserver *s, const std::string& name)
    {
        printer::printerClient *pClient = new printer::printerClient;
        printer::printerClient::Config cC(s, name);
        pClient->initialise(cC);

        return pClient;
    }


    bool release(printer::IFclient *cln)
    {
        delete cln;
        return true;
    }

    IFserver * obtain(const std::string& name)
    {
        printer::printerServer *pServer = new printer::printerServer;
        printer::printerServer::Config cS(name);
        pServer->initialise(cS);

        return pServer;    
    }

    bool release(printer::IFserver *srv)
    {
        delete srv;
        return true;
    }

    bool test(printer::IFserver *srv, printer::IFclient *cln)
    {

        bool r =  false;

        std::cout << "test() will use one printerClient and one printerServer" << std::endl;
        std::cout << "... start" << std::endl;

        std::vector<std::string> &ss = getpattern();
        print(ss);

        std::cout << "The printer client obtains:" << std::endl;
        for(size_t i=0; i<ss.size(); i++)
        {
            std::string s = ss[i];
            cln->send(s);        
        }  


        std::cout << "... end" << std::endl << std::endl;

        r = true;
        return r;

    }

    bool test(printer::IFserver *srv, printer::IFclient *cln0, printer::IFclient *cln1)
    {
        bool r =  false;

        std::cout << "test() will use two one printerClient and one printerServer" << std::endl;
        std::cout << "... start" << std::endl;

        std::vector<std::string> &ss = getpattern();
        print(ss);

        std::cout << "The first printer client obtains:" << std::endl;
        for(size_t i=0; i<ss.size(); i++)
        {
            std::string s = ss[i];
            cln0->send(s);        
        }  

        std::cout << "The second printer client obtains:" << std::endl;
        for(size_t i=0; i<ss.size(); i++)
        {
            std::string s = ss[i];
            cln1->send(s);        
        }  

        std::cout << "... end" << std::endl << std::endl;

        r = true;
        return r;

    }

    


}}   // namespace printer { namespace test {



// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


