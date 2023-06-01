
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



#include<iostream>

#include "mcore01.h"

int main(int argc, char *argv[]) 
{
   std::cout << "Hello World! of Modern C++" << std::endl;

   // nullptr 
   mcore01::ex01::run();

   // auto
   mcore01::ex02::run();
   
   // typealiases
   mcore01::ex03::run();   

   // initializerlist
   mcore01::ex04::run();

   // uniforminitialization
   mcore01::ex05::run();
   return 0;
}
