

# Printing objects



In here is described the implementation of two printing objects, `printClient` and `printServer`, as per request of the test assignment in [here](../../../day01/assignment/TestAssigment.md).



## Brief introduction

The exercise asks to develop two objects which acts as a printing client and a printing server. They must hide implementation with the PIMPL idiom and present minimal interface.

Also, a test must be prepared so that a given sequence of strings is passed to the client which sends to the server for the actual print.



## Some details

In here are some details.

### The interface

I have defined a minimal interface using pure virtual classes.

```C++

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
```

**Code Listing**. The client just needs to send a string and the server to accept it.

 

### The `printServer`

I have used the PIMPL with following public API. Apart from the functions required by the PIMPL and the `IFserver` interface, I have added a `initialise()` method which just adds a name to the server. It is not strictly required but it may be useful.

The internals of the `printerServer` will print the received string maybe prefixed by the name of the server.

```C++
namespace printer {

    class printerServer: public IFserver
    {
    public:
            
        struct Config
        {            
            std::string name;
            Config() : name("") {}
            Config(const std::string n) : name(n) {}
        };   

        printerServer(); 
        ~printerServer();                          
                
        bool initialise(const Config &config);   
        bool receive(const std::string &str);        
        
    private:
        printerServer(const printerServer&);            
        printerServer& operator=(const printerServer&); 

        struct Impl;
        Impl* pImpl;    
    }; 

}   // namespace printer {

```

**Code Listing**. The class `printerServer`.



### The `printClient`

In here as well I have added a `initialise()` method which just adds a name to the server. That is purely cosmetic.

The internals of the `printerClient` will send the string to a server. But which one, and how? I have solved it by adding a `IFserver *` inside the `printerClient::Config`. Well, that is important.

```C++
namespace printer {
    
    class printerClient : public IFclient
    {
    public:
            
        struct Config
        {        
            IFserver * srv;  // NOTE: so that the Impl can use srv->receive()
            std::string name;    
            Config() : srv(NULL), name("") {}
            Config(IFserver *s, std::string n) : srv(s), name(n) {}
        };   

        printerClient(); 
        ~printerClient();                          
                
        bool initialise(const Config &config);   
        bool send(const std::string &str);        
        
    private:
        printerClient(const printerClient&);            
        printerClient& operator=(const printerClient&); 

        struct Impl;
        Impl* pImpl;    
    }; 

    
}   // namespace printer {

```

**Code Listing**. The class `printerClient`.



### The test

I have decide to write a specific test for the two objects. The test just creates a client and a server and makes the client print to the server. In here are the used API.



```C++

namespace printer { namespace test {

    // they retrieve the pattern and print it 
    std::vector<std::string> & getpattern();
    bool print(const std::vector<std::string>& ss);

    // they obtain or release a server or a client.
    IFclient * obtain(IFserver *s, const std::string& name = "");
    bool release(printer::IFclient *cln);
    IFserver * obtain(const std::string& name = "");
    bool release(printer::IFserver *srv);

    // it tests one server and one client
    bool test(printer::IFserver *srv, printer::IFclient *cln);

    // it tests two clients sending to the same server
    bool test(printer::IFserver *srv, printer::IFclient *cln0, printer::IFclient *cln1);
    
}}  // namespace printer { namespace test {

```

**Code Listing**. The test namespace.



And in here is the caller





```C++
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

   return 0;
}


```

**Code Listing**. The test caller.



## How to compile and run

From folder `exercises/day04` digit:

```bash
day04$ mkdir build
day04$ cd build
day04/build$ cmake -DCMAKE_CXX_STANDARD="98" ..
day04/build$ make
day04/build$ ./test
test() will use one printerClient and one printerServer
... start
The pattern is:
hello
world
of
modern
C++
...
The printer client obtains:
SRV: from CLN: hello
SRV: from CLN: world
SRV: from CLN: of
SRV: from CLN: modern
SRV: from CLN: C++
... end
day04/build$
```

**Listing**. Compile instructions







