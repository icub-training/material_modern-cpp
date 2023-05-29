
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __PRINTERIF_H_
#define __PRINTERIF_H_



#include <string>

namespace printer {


    class IFclient
    {
    public:
        virtual bool send(const std::string &str) = 0;
        virtual ~IFclient() {};
    };

    class IFserver
    {
    public:
        virtual bool receive(const std::string &str) = 0;
        virtual ~IFserver() {};
    };


}   // namespace printer {
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


