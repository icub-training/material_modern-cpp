
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


#include "printerTest.h"

int main(int argc, char *argv[]) 
{
    printer::IFserver *srv = NULL;
    printer::IFclient *cln = NULL;

    srv = printer::test::obtain("SRV");
    cln = printer::test::obtain(srv, "CLN");

    printer::test::test(srv, cln);

    printer::test::release(srv);
    printer::test::release(cln);

#if 0
    printer::IFclient *cln1 = NULL;
    srv = printer::test::obtain("SRV");
    cln = printer::test::obtain(srv, "CLN");
    cln1 = printer::test::obtain(srv, "CLN1");

    printer::test::test(srv, cln, cln1);

    printer::test::release(srv);
    printer::test::release(cln);
    printer::test::release(cln1);
#endif

   return 0;
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


