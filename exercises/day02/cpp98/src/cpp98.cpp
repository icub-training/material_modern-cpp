
/*
 * Copyright (C) 2023 iCub Tech - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
*/



// --------------------------------------------------------------------------------------------------------------------
// - public interface
// --------------------------------------------------------------------------------------------------------------------

#include "cpp98.h"


// --------------------------------------------------------------------------------------------------------------------
// - external dependencies
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>

#include<iostream>

// --------------------------------------------------------------------------------------------------------------------
// - pimpl: private implementation (see scott meyers: item 22 of effective modern c++, item 31 of effective c++
// --------------------------------------------------------------------------------------------------------------------



// --------------------------------------------------------------------------------------------------------------------
// - all the rest
// --------------------------------------------------------------------------------------------------------------------

// MODERNC++PREREQUISITES-forloop
void test()
{
    int count = 0;
    for(int i=0; i<42; i++)
    {
        count ++;
    }
}

namespace test01 {
     
#if 0    
    void runit()
    { 
        run1();
        run2();
    }  
#endif

    // MODERNC++PREREQUISITES-aminimalclass-test
    void run1()
    {
        LN ln1(99);       
        ln1.set(1);                   
        posv_t value = ln1.get();
        value = value;
    }   

    // MODERNC++PREREQUISITES-specialmemberfunctions-test
    void run2()
    {
        LN ln1(99, 1);        
        // the following works fine using what the compiler implicitly generates:
        // copy assignment (ca), copy constructor (cc), destructor (dtor)
        LN lnx = ln1;   // calls ca
        lnx = 7;        // calls LN(7), then ca    
        lnx = LN(3, 4); // calls ctor and then ca
        posv_t vv0 = lnx.get();
        LN lny = LN(ln1);   // calls cc, then ca
        posv_t vv1 = lny.get(); 
        vv1 = vv1;   
    }   // dtor for: ln1, lnx, lny
    
} // namespace test01


// MODERNC++PREREQUISITES-aminimalclass-impl
namespace test01 {
    
    LN::LN(const posv_t max, const posv_t val) : m_m(max), m_v(std::min(max, val)) 
    {
        std::cout << "LN::CTOR -> " << "m_m = " << m_m << ", m_v = " << m_v << std::endl;
    }

    #if defined(LN_hasDTOR)
        LN::~LN()
        {
             std::cout << "LN::DTOR -> " << "m_m = " << m_m << ", m_v = " << m_v << std::endl;
        }
    #endif

    posv_t LN::get() const 
    { 
        return m_v; 
    }

    void LN::set(const posv_t val) 
    { 
        m_v = std::min(val, m_m); 
    } 

} // namespace test01


// MODERNC++PREREQUISITES-ruleofthree-test
namespace test02 {

    void runit()
    {
        BAD ln1(10, 99);
        
        ln1.set(0, 1);
        
        BAD ln2(20, 55);
                
        posv_t value0 = ln1.get(0);
        posv_t value1 = ln1.get(1);
                
        BAD lnx = ln1;
        lnx = BAD(15, 77);
        
        lnx = lnx;
        
        BAD lny = BAD(ln1);
        posv_t vv = lny.get(3);
        
        if(1 == vv)
        {
            lny.set(0, 3);
        }

    }

    
} // namespace test02

// MODERNC++PREREQUISITES-ruleofthree-impl
namespace test02 {
    
    BAD::BAD(const size_t capacity, const posv_t max, const posv_t val) : 
        m_c(capacity), m_m(max) 
    {
        m_vv = new posv_t[m_c];
        for(size_t i=0; i<m_c; i++) m_vv[i] = std::min(val, m_m);
    }

    posv_t BAD::get(const size_t pos) const 
    { 
        return (pos<m_c) ? m_vv[pos] : 0; 
    }

    void BAD::set(const size_t pos, const posv_t val) 
    { 
        if(pos<m_c)
            m_vv[pos] = std::min(val, m_m);
    } 
        
}


// MODERNC++PREREQUISITES-ruleofthree-test-ok
namespace test03 {

    void runit()
    {
        ALN ln1(10, 99);
        
        ln1.set(0, 1);
        
        ALN ln2(20, 55);
                
        posv_t value0 = ln1.get(0);
        posv_t value1 = ln1.get(1);
                
        ALN lnx = ln1;
        lnx = ALN(15, 77);
        
        lnx = lnx;
        
        ALN lny = ALN(ln1);
        posv_t vv = lny.get(3);
        
        if(1 == vv)
        {
            lny.set(0, 3);
        }
    }
         
    
} // namespace test03


// MODERNC++PREREQUISITES-ruleofthree-impl-ok
namespace test03 {
    
    ALN::ALN(const size_t capacity, const posv_t max, const posv_t val) : 
        m_c(capacity), m_m(max) 
    {
        m_vv = new posv_t[m_c];
        for(size_t i=0; i<m_c; i++) m_vv[i] = std::min(val, m_m);
    }

    posv_t ALN::get(const size_t pos) const 
    { 
        return (pos<m_c) ? m_vv[pos] : 0; 
    }

    void ALN::set(const size_t pos, const posv_t val) 
    { 
        if(pos<m_c)
            m_vv[pos] = std::min(val, m_m);
    } 
    
    
    ALN::ALN(const ALN &other) : m_c(other.m_c), m_m(other.m_m) 
    {
       m_vv = new posv_t[m_c];
       for(size_t i=0; i<m_c; i++) m_vv[i] = other.m_vv[i];       
    }
    
    ALN& ALN::operator=(const ALN &other) 
    {
        if(&other == this) { return *this; }  // self-assignment [11]
        
        m_c = other.m_c;
        m_m = other.m_m;
        m_vv = new posv_t[m_c];
        for(size_t i=0; i<m_c; i++) m_vv[i] = other.m_vv[i];
        return *this;  // [10]  
    }  

    ALN::~ALN()
    {
        if(NULL != m_vv) delete[] m_vv;
    }    

} // namespace test03



// MODERNC++PREREQUISITES-composition-test
namespace test06 {

    void runit()
    {
        LPAIR lp(99, 2, 3);
        lp.set(3, 4);
        posv_t v0 = 0;
        posv_t v1 = 1;
        lp.get(v0, v1);
    }

} // namespace test06 {
    
    
// MODERNC++PREREQUISITES-composition-impl    
namespace test06 {   

    LPAIR::LPAIR(const posv_t max, const posv_t v0, const posv_t v1) : ln0(max, v0), ln1(max, v1) {}

    void LPAIR::get(posv_t &v0, posv_t &v1) const 
    { 
        v0 = ln0.get();
        v1 = ln1.get(); 
    }

    void LPAIR::set(const posv_t v0, const posv_t v1) 
    { 
        ln0.set(v0);
        ln1.set(v1); 
    } 

} // namespace test06


// MODERNC++PREREQUISITES-inheritance-test 
namespace test07 {

    void runit()
    {
        Shape sh(test06::LPAIR(100, 2, 2), 25);
        size_t a = sh.getarea();
        sh.draw();


        Square sq(test06::LPAIR(100, 2, 2), 3);
        size_t area = sq.getarea();
        sq.resize(4);
        area = sq.getarea();
        area =  area;
        sq.draw();

        Shape *polym = new Square(test06::LPAIR(100, 2, 2), 3);
        polym->moveto(test06::LPAIR(100, 9, 9));
        polym->draw();
    }

}

// MODERNC++PREREQUISITES-inheritance-impl
namespace test07 {

    Shape::Shape(const test06::LPAIR &position, size_t area) : _pos(position), _area(area) {}

    size_t Shape::getarea() const
    {
        return _area;
    }                        
    
    void Shape::moveto(const test06::LPAIR &position)
    {
        _pos = position;
    }

    void Shape::draw()
    {
        static size_t as_a_shape = 0;
        as_a_shape++;
        std::cout << "Shape::draw() is called" << std::endl;
    }

    Square::Square(const test06::LPAIR &position, const size_t len) : Shape(position, len*len), _len(len) {}

    void Square::resize(size_t len)
    {
        _len = len;
        // must now operate on protected members of Shape
        _area = len*len;
    }

    void Square::draw()
    {
        static size_t as_a_square = 0;
        as_a_square++;  
        std::cout << "Square::draw() is called" << std::endl;      
    }


} // namespace test07



// MODERNC++PREREQUISITES-interface-test
namespace test04 {

    void runit()
    {
        Person *p = generate("Scott Meyers");
        p->setsomething(3);
        int smt = p->getsomething();
        smt = smt; 
        
        delete p;
    }

}

// MODERNC++PREREQUISITES-interface-impl
namespace test04 {
    
    class RealPerson: public Person 
    {
    public:
        RealPerson(const std::string& name) : _n(name), _e(0) {}
        virtual ~RealPerson() {}
        std::string getname() const { return _n; }
        int getsomething() const { return _e; }
        void setsomething(const int &v) { _e = v; }
    private:
        std::string _n;
        int _e;
    };

    Person * generate(const std::string& name)
    {
        return new RealPerson(name); 
    }


} // namespace test04


// MODERNC++PREREQUISITES-interface-test
namespace test05 {

    void runit()
    {
        DeviceDriver *d = generate(DeviceDriver::type0, 999);
        d->open();
        d->write(100);
        int vv = d->read();
        vv = vv;

        delete d;
    }
}

// MODERNC++PREREQUISITES-interface-test
namespace test05 {
    class DD: public DeviceDriver {
    public:
        DD(const DeviceDriver::Type t, int id) : _t(t), _i(id) { _v = 0; }
        virtual ~DD() {}
        int getID() const { return _i; }
        void open() { }
        void close() { }
        int read() const { return _v; }
        void write(const int &v) { _v = v; }
    private:
        DeviceDriver::Type _t;
        int _i;
        int _v;
    };   


    DeviceDriver * generate(const DeviceDriver::Type type, int ID)
    {
        return new DD(type, ID); 
    }

} // namespace test05

// -------------------------------------------------------------------------------------------------------------------
// MODERNC++PREREQUISITES-pimpl-api
// C++98: the PIMPL [], page 26

namespace pimpl {

    void test()
    {
        Parser parser("some options");
        std::string str = "string to parse";
        parser.parse(str.c_str());
    }


    // the implementation

    struct Parser::Impl
    {      
        Impl(const char *params) 
        {
            // dont use it so far
        }
                   
        void parse(const char *input)
        {
            // i just ... prints it as a string
            if(NULL == input)
            {
                return;
            }
            std::cout << "Parser::Impl::parse()  is processing: " << input << std::endl;        
        }
        
    };


    // the interface

    Parser::Parser(const char *params)
    {
        pImpl = new Impl(params);
    }  
        
    Parser::~Parser() 
    { 
        delete pImpl;
    }
            
    void Parser::parse(const char *input)
    {
        pImpl->parse(input);
    }

}

// MODERNC++PREREQUISITES-stl-test

#include <vector>
#include <algorithm>

namespace test08 {

    void runit()
    {
        std::vector<int> vv;
        vv.push_back(3);
        vv.push_back(1);
        vv.push_back(5); 
        // now the vector contains three values: {3, 1, 5}
        std::cout << "vector vv contains " << vv.size() << " elements:" << std::endl; 
        for(size_t i=0; i<vv.size(); i++)
        {
           std::cout << "vv[" << i << "] =" << vv[i] << std::endl;  
        }        
        // ok, now i want to sort the vector.
        std::sort(vv.begin(), vv.end());
        // ok, now the order is {1, 3, 5}
        std::cout << "after sorting vector vv contains " << vv.size() << " elements:" << std::endl; 
        for(size_t i=0; i<vv.size(); i++)
        {
           std::cout << "vv[" << i << "] =" << vv[i] << std::endl;  
        }

        // is there the number 3 inside?
        const int numbertofind = 3;
        std::vector<int>::iterator r = std::find(vv.begin(), vv.end(), numbertofind);
        bool found = false;
        if(r != vv.end())
        {
            found = true;
        }

        std::cout << "did std::find() find number " << numbertofind << "?" << std::endl; 
        std::cout << (found ? "YES!" : "I'm sorry, no") << std::endl;
    }   

} // namespace test08    


#if 0
// MODERNC++THEBASICS

namespace test11 {

    void f(int a);
    void f(char *a);


    void runit()
    {
        f(0);  	        // calls f(int a) 
    //    f(NULL);  	    // calls f(int a): it is not what we wanted
        f(nullptr);  	// calls f(char *a) 
    }


    void f(int a)
    {
        std::cout << "called f(int a)" << std::endl;    
    }

    void f(char *a)
    {
        std::cout << "called f(char *a)" << std::endl;    
    }

} // namespace test11   

#endif


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




