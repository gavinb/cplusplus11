
#include <iostream>
#include <memory>

// Base class with virtual method
class Base0
{
public:
    virtual void foo(int num)
    {
        std::cout << "Base0::foo(int)" << std::endl;
    }
};

// Derived class with mismatched type.
// This error will not be caught.
class Derived0 : public Base0
{
public:
    virtual void foo(float num)
    {
        std::cout << "Derived0::foo(float)" << std::endl;
    }
};

// Base class with virtual method
class Base1
{
public:
    virtual void foo(int num)
    {
        std::cout << "Base1::foo(int)" << std::endl;
    }
};

// Derived class intends to override.
// Since parent type signature doesn't match,
// this error will be caught
class Derived1 : public Base1
{
public:
//    virtual void foo(float num) override
    virtual void foo(int num) override
    {
        std::cout << "Derived1::foo(int)" << std::endl;
    }
};

int main(int argc, char* argv[])
{
    // Test method resolution

    std::unique_ptr<Base0>   b0(new Base0);
    std::unique_ptr<Base0>   d0(new Derived0);

    // These will both call Base0::foo

    b0->foo(123);
    d0->foo(123);

    // Test method resolution

    std::unique_ptr<Base1>   b1(new Base1);
    std::unique_ptr<Base1>   d1(new Derived1);

    // These will call the correct method override

    b1->foo(123);
    d1->foo(123);

    return 0;
}
