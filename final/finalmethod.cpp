
#include <iostream>

class Base0
{
    virtual void foo();
};

class Derived0 : Base0
{
    void foo();
};

class Base1
{
    virtual void foo() final;
};

class Derived1 : Base1
{
    void foo();
};

int main(int argc, char* argv[])
{
    return 0;
}
