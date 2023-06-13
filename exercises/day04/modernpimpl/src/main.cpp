
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


#include "modernprinter.h"

int main(int argc, char *argv[]) 
{
     modern::printer::Client *c {nullptr};
     modern::printer::Client cli {};

    {   // first scope
        modern::printer::theServer &srv = modern::printer::theServer::getInstance();
        srv.initialise({});
        srv.receive("hello, i am the server and i am ready to accept a string from a client");
    }

    {   // second scope: at exit client01 calls its ctor
        modern::printer::Client client01 {};
        client01.initialise({"Client01"});
        client01.send("first test print");
    }

    {   // third scope: at exit cl does not call its ctor
        modern::printer::Client *cl = new modern::printer::Client;
        cl->initialise({"Client02ptr"});
        cl->send("second test print");
        c = cl;
        // cli = *cl; // can call the copy assignment operator?
    }

    delete c;



    return 0;
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


