
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __PRINTERTEST_H_
#define __PRINTERTEST_H_

#include "printerIF.h"
#include "printerClient.h"
#include "printerServer.h"

#include <vector>
#include <string>

namespace printer { namespace test {

    // they retrieve the pattern and print it 
    std::vector<std::string> & getpattern();
    bool print(const std::vector<std::string>& ss);

    // they obtain or release a server or a client.
    IFclient * obtain(IFserver *s, const std::string& name = "");
    bool release(printer::IFclient *cln);
    IFserver * obtain(const std::string& name = "");
    bool release(printer::IFserver *srv);

    // it tests one server and one client
    bool test(printer::IFserver *srv, printer::IFclient *cln);

    // it tests two clients sending to the same server
    bool test(printer::IFserver *srv, printer::IFclient *cln0, printer::IFclient *cln1);
    
}}  // namespace printer { namespace test {
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


