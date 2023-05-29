
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



#include<iostream>

#include "cpp98.h"

int main(int argc, char *argv[]) 
{
   std::cout << "Hello World! of Modern C++" << std::endl;


#if 1

   // MODERNC++PREREQUISITES-forloop-run
   test();
   
   // MODERNC++PREREQUISITES-aminimalclass-run
   test01::run1();
   
   // MODERNC++PREREQUISITES-specialmemberfunctions-run
   test01::run2();


   // MODERNC++PREREQUISITES-ruleofthree-run
   test02::runit();
   
   // MODERNC++PREREQUISITES-ruleofthree-run-ok
   test03::runit();
   
   
   // MODERNC++PREREQUISITES-composition-run
   test06::runit();
   
   // MODERNC++PREREQUISITES-inheritance-run
   test07::runit();
   
   // MODERNC++PREREQUISITES-interface-run
   test04::runit();   
   test05::runit();

   // MODERNC++PREREQUISITES-pimpl-run
   pimpl::test();
   
   // MODERNC++PREREQUISITES-stl-run
   test08::runit();
   
#endif
      
   
   return 0;
}
