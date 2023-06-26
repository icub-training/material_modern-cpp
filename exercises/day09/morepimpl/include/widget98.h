
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/

// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __WIDGET98_H_
#define __WIDGET98_H_



namespace cpp98::pimpl {

    class Widget { 
    public:
        Widget();
        ~Widget();      // needed
        
        void doit();

    private:
        struct Impl;    // declare implementation struct
        Impl *pImpl;    // and pointer to it  
    }; 
};  
    

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


