
#include <iostream>

class Base0
{
};

class Derived0 : Base0
{
};

class Base1 final
{
};

class Derived1 : Base1
{
};

int main(int argc, char* argv[])
{
    return 0;
}
