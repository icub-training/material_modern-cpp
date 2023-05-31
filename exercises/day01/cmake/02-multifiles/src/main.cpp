
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


#include<iostream>
#include "cpptest.h"

int main(int argc, char *argv[]) 
{
   std::cout << "Hello World! of Modern C++. We are using more source files" << std::endl;
   d01::test01::say("hello world");
   d01::test01::say("hello world");
   for(size_t i=0; i<7; i++)
   {
      d01::test01::say("hello world");
   }
   
   return 0;
}
