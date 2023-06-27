
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



#include "widget98.h"
#include "modernpimpl.h"

int main(int argc, char *argv[]) 
{
    {   // widget 98
        cpp98::pimpl::Widget widget98;
        widget98.doit();
    }

    // {   // modern widget v00
    //     modern::pimpl::v00::Widget widget00;
    //     widget00.doit();    
    // }

    {   // modern widget v01: 
        // - non copiable (unique ptr), 
        // - non moveable (does not know how to do it because of item 17)
        modern::pimpl::v01::Widget widget01;
        widget01.doit();   
        //modern::pimpl::v01::Widget w01a = widget01; 
        //modern::pimpl::v01::Widget w01b = std::move(widget01);
    }

    {   // modern widget v02: 
        // - non copiable (unique ptr), 
        // - moveable
        modern::pimpl::v02::Widget widget02;
        widget02.doit();   
        // modern::pimpl::v02::Widget w02a = widget02; 
        modern::pimpl::v02::Widget w02b = std::move(widget02);
    }

    {   // modern widget v03: 
        // - copiable despite the unique_ptr, 
        // - moveable
        modern::pimpl::v03::Widget widget03;
        widget03.doit();   
        modern::pimpl::v03::Widget w03a = widget03; 
        modern::pimpl::v03::Widget w03b = std::move(widget03);
        w03a = w03a;
    }

    {   // modern widget v04: 
        // - non copiable, 
        // - non moveable

        modern::pimpl::v04::Widget widget04;
        widget04.doit();   
    //    modern::pimpl::v04::Widget w04a = widget04; 
    //    modern::pimpl::v04::Widget w04b = std::move(widget04);
    //    w04a = w04a;
    }

   {   // modern widget v05:  shared pointer
        // - copiable, 
        // - moveable

        modern::pimpl::v05::Widget widget05;
        widget05.doit();   
        modern::pimpl::v05::Widget w05a = widget05; 
        modern::pimpl::v05::Widget w05b = std::move(widget05);
        w05a = w05a;
    }

    {   // modern singleton: 
        // - non copiable, 
        // - non moveable
        // - non destructable ?? why should I define the ctor? the compiler will do that for me

        modern::pimpl::singleton::theOne &theone = modern::pimpl::singleton::theOne::getInstance();
        theone.doit();   
    }

    return 1;
}


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


