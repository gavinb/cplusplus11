// std::unique_ptr example 5
// Allocation of array

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

    const unsigned N = 10;

    std::cout << "    allocate\n";

    std::unique_ptr<Foo[]> objarray(new Foo [N]);

    std::cout << "    process\n";

    for (unsigned i = 0; i < N; i++)
    {
        std::cout << i << " ";
        objarray[i].process();
    }

    std::cout << "--- main()\n";

    std::cout << "    release\n";

    return 0;
}
