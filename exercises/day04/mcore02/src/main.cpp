
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



#include<iostream>

#include "mcore02.h"

int main(int argc, char *argv[]) 
{
   std::cout << "Hello World! of Modern C++" << std::endl;

   // std::array<> 
   mcore02::ex06::run();

   // range based loop
   mcore02::ex07::run();

   // constexpr
   mcore02::ex08::run();   

   // enum+constexpr
   mcore02::ex09::run();

   // override
   mcore02::ex10::run();
   return 0;
}
