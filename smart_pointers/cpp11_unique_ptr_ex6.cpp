// std::unique_ptr example 5
// Using unique_ptr with vector containers

#include <memory>
#include <iostream>
#include <vector>

class Foo
{
public:
    Foo(int a) : _a(a) { std::cout << "+++ Foo::Foo(a=" << _a << ")\n"; }
    ~Foo() { std::cout << "--- Foo::~Foo()\n"; }
    void process() { std::cout << "... Foo::process() a=" << _a << "\n"; }
private:
    int _a;
};

int main(int argc, char* argv[])
{
    std::cout << "+++ main()\n";

    const unsigned N = 20;

    std::cout << "    allocating vector of N=" << N << " objects\n";

    std::vector< std::unique_ptr<Foo> > v;

    for (unsigned i = 0; i < N; i++)
    {
        std::unique_ptr<Foo> q(new Foo(i));
        v.push_back(std::move(q));
    }

    std::cout << "    processing vector of N=" << N << " objects\n";

    for (unsigned i = 0; i < N; i++)
    {
        v[i]->process();
    }

    std::cout << "--- main()\n";

    return 0;
}
