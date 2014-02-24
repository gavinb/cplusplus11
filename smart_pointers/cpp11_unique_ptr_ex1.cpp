// std::unique_ptr example 1
// Implicit cleanup

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

    std::cout << "--- main()\n";

    return 0;
}
