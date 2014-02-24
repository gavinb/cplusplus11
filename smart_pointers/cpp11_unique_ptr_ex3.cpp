// std::unique_ptr example 3
// Attempted assignment - @note will not compile!

#include <memory>
#include <iostream>

class Foo
{
public:
    Foo() { std::cout << "+++ Foo::Foo()\n"; }
    ~Foo() { std::cout << "--- Foo::~Foo()\n"; }
    void process() { std::cout << "... Foo::process()\n"; }
};

int main(int argc, char* argv[])
{
    std::cout << "+++ main()\n";

    std::unique_ptr<Foo> obj(new Foo);
    obj->process();

    std::unique_ptr<Foo> obj2;

    // Will not compile!
    #ifdef TRY_TO_COMPILE
    obj2 = obj;
    #endif

    std::cout << "--- main()\n";

    return 0;
}
