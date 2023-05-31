
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/


// - include guard ----------------------------------------------------------------------------------------------------

#ifndef __CPP_98_H_
#define __CPP_98_H_

#include <cstddef>
#include <string>
typedef unsigned int posv_t;

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-forloop-api
// C++98: the for loop [], page 4

void test();

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-aminimalclass-api
// C++98: a minimal class [] [], page 6
// MODERNC++PREREQUISITES-aminimalclass-api
// C++98: special member functions [] [], page 10

namespace test01 {
    
    void run1(); // amimimalclass
    void run2(); // specialmemberfunctions  

    #define LN_hasDTOR

    class LN 
    {   // Limited Number
    public:        
        LN(const posv_t max, const posv_t val = 0); // ctor

        posv_t get() const;                         // getter
        void set(const posv_t val);                 // setter 

        #if defined(LN_hasDTOR)
        ~LN();
        #endif

    private:
        posv_t m_m;
        posv_t m_v;                                 // implementation
    };   
            
}  // namespace test01


// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-ruleofthree-api
// C++98: the rule of three [] [] [], page 13

namespace test02 {
    
    void runit();

    class BAD 
    {   // BAD: Array of Limited Numbers
    public:        
        BAD(const size_t capacity, const posv_t max, const posv_t val = 0); // ctor

        posv_t get(const size_t pos) const;                 // getter 
        void set(const size_t pos, const posv_t val);       // setter    

    private:
        size_t m_c;
        posv_t m_m;
        posv_t *m_vv;                                       // implementation 
    };    
       
}  // namespace test02

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-ruleofthree-api-ok
// C++98: the rule of three [] [] [] [], page 14

namespace test03 {
    
    void runit();
       
    class ALN 
    {   // Array of Limited Numbers
    public:        
        ALN(const size_t capacity, const posv_t max, const posv_t val = 0); // ctor

        posv_t get(const size_t pos) const;                 // getter
        void set(const size_t pos, const posv_t val);       // setter   

        ALN(const ALN &other);                              // copy ctor
        ALN& operator=(const ALN &other);                   // copy assignment 
        ~ALN();                                             // dtor

    private:
        size_t m_c;
        posv_t m_m;
        posv_t *m_vv;                                       // implementation
    };   
            
}  // namespace test03


// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-composition-api
// C++98: composition of classes [], page 15

namespace test06 {

    void runit();

    class LPAIR 
    {
    public:
        LPAIR(const posv_t max, const posv_t v0 = 0, const posv_t v1 = 0);

        void get(posv_t &v0, posv_t &v1) const;                         
        void set(const posv_t v0, const posv_t v1);

    private:
        test01::LN ln0;
        test01::LN ln1;
    };
            
}  // namespace test06

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-inheritance-api
// C++98: base class [], page 17
// C++98: derived class [], page 19

namespace test07 {

    void runit();

    class Shape 
    {
    public:
        Shape(const test06::LPAIR &position, size_t area);
        size_t getarea() const;                         
        void moveto(const test06::LPAIR &position);
        virtual void draw();
    protected:
        test06::LPAIR _pos;
        size_t _area;
    };


    class Square : public Shape
    {
    public:
        Square(const test06::LPAIR &position, const size_t len);
        void resize(size_t len);
        virtual void draw();
    private:
        size_t _len;
    };
            
}  // namespace test07

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-interface-api
// C++98: the interface class [], page 23

namespace test04 {
    
    void runit();
       
    class Person 
    {   // no ctor, no data. only: a virtual dtor + pure virtual functions
    public:
        virtual std::string getname() const = 0;    
        virtual int getsomething() const = 0;
        virtual void setsomething(const int &v) = 0; 
        virtual ~Person() {};
    };

    Person * generate(const std::string& name);

}  // namespace test04

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-interface-api
// another example of interface class

namespace test05 {

    void runit();

    struct DeviceDriver 
    {
        enum Type { type0, type1 };
        virtual int getID() const = 0;
        virtual void open() = 0;
        virtual void close() = 0;
        virtual int read() const = 0;
        virtual void write(const int &v) = 0;
        virtual ~DeviceDriver() {};
    };

    DeviceDriver * generate(const DeviceDriver::Type type, int ID);
            
}  // namespace test05

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-pimpl-api
// C++98: the PIMPL [], page 26

namespace pimpl {

    void test();

    class Parser
    {
    public:
        Parser(const char *params); 
        ~Parser();                          
                    
        void parse(const char *input);

    private:
        Parser(const Parser&);              // non copyable         
        Parser& operator=(const Parser&);   //  

        struct Impl;                        // forward declataion of implementation class
        Impl* pImpl;                        // the PIMPL
    }; 

}

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-stl-api
// C++98: the std::vector<> [][][], page 31

namespace test08 {

    void runit();
            
}  // namespace test08


#if 0
namespace test11 {

    void runit();
            
}  // namespace test11
#endif

#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------


