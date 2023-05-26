



#include<iostream>

#define __USE_CPP98

int main(int argc, char *argv[]) 
{

#if defined(__USE_CPP98)
#else   
   auto iammodern{3};
   iammodern++;
 #endif

   std::cout << "Hello World! of Modern C++" << std::endl;
   return 0;
}
