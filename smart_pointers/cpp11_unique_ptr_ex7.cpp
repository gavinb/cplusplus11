// std::unique_ptr example 5
// Very simple measurement of the overhead of unique_ptr for method calls

#include <memory>
#include <thread>
#include <chrono>
#include <iostream>
#include <cassert>

const unsigned wait_time_us = 200;
const unsigned N = 10000;
const unsigned delay = wait_time_us * N;

class Foo
{
public:
    Foo() { std::cout << "+++ Foo::Foo()\n"; _a = 42; }
    ~Foo() { std::cout << "--- Foo::~Foo()\n"; }
    int process() { std::this_thread::sleep_for(std::chrono::microseconds(wait_time_us)); return _a; }
private:
    int _a;
};

int main(int argc, char* argv[])
{
    std::cout << "+++ main()\n";

    unsigned time_bare = 0;
    unsigned time_unique = 0;
    unsigned sum_bare = 0; // Prevent opt
    unsigned sum_unique = 0; // Prevent opt

    // bare: without smart pointer
    {
        Foo* obj = new Foo;

        auto time_before = std::chrono::system_clock::now();

        for (unsigned i = 0; i < N; i++)
        {
            sum_bare += obj->process();
        }

        auto time_after = std::chrono::system_clock::now();

        time_bare = std::chrono::duration_cast<std::chrono::microseconds>(time_after-time_before).count() - delay;

        delete obj;
    }

    // unique: using unique_ptr
    {
        std::unique_ptr<Foo> obj(new Foo);

        auto time_before = std::chrono::system_clock::now();

        for (unsigned i = 0; i < N; i++)
        {
            sum_unique += obj->process();
        }

        auto time_after = std::chrono::system_clock::now();

        time_unique = std::chrono::duration_cast<std::chrono::microseconds>(time_after-time_before).count() - delay;
    }

    assert(sum_bare == sum_unique);

    std::cout << "Iterations:  " << N << std::endl;
    std::cout << "Delay:       " << delay << std::endl;
    std::cout << "Time bare:   " << time_bare << std::endl;
    std::cout << "Time unique: " << time_unique << std::endl;

    if (time_unique > time_bare)
    {
        float pc = (time_unique - time_bare) / (float)time_bare * 100.0f;

        std::cout << "unique_ptr overhead: " << pc << "%" << std::endl;
    }
    else
    {
        float pc = (time_bare - time_unique) / (float)time_unique * 100.0f;

        std::cout << "unique_ptr speedup:  " << pc << "%" << std::endl;
    }

    return 0;
}
