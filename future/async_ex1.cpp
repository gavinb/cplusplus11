/*
 */

#include <iostream>
#include <future>

unsigned Fib(unsigned n)
{
    return n<=2 ? 1 : Fib(n-1) + Fib(n-2);
}

unsigned calc1()
{
    std::cout << "+++ calc1 started" << std::endl;

    unsigned ans = Fib(35);

    std::cout << "--- calc1 complete" << std::endl;

    return ans;
}

unsigned calc2()
{
    std::cout << "+++ calc2 started" << std::endl;

    unsigned ans = Fib(40);

    std::cout << "--- calc2 complete" << std::endl;

    return ans;
}

int main()
{
    std::future<unsigned> result1 = std::async(calc1);
    std::future<unsigned> result2 = std::async(calc2);

    bool ready = false;
    std::chrono::milliseconds wait_time_ms(5);

    auto status_fn = [](unsigned i, std::future_status st) -> bool
    {
        switch (st)
        {
            case std::future_status::ready:
                std::cout << i << ": ready\n";
                break;
            case std::future_status::timeout:
                std::cout << i << ": busy\n";
                break;
            case std::future_status::deferred:
                std::cout << i << ": deferred\n";
                break;
        }
        return st == std::future_status::ready;
    };

    while (!ready)
    {
        std::future_status status1 = result1.wait_for(wait_time_ms);
        std::future_status status2 = result2.wait_for(wait_time_ms);

        ready = status_fn(1, status1) && status_fn(2, status2);
    }

    unsigned result = result1.get() + result2.get();

    std::cout << "calc1() + calc2() = " << result << std::endl;

    return 0;
}
