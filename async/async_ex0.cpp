/*
    Simplest possible async/future example
 */

#include <iostream>
#include <future>
#include <chrono>

unsigned boring()
{
    std::cout << "+++ boring started" << std::endl;

    // Pretend to do some work that takes time
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "--- boring complete" << std::endl;

    return 42;
}

int main()
{
    std::cout << "+++ main" << std::endl;
    std::cout << "    Starting async" << std::endl;

    std::future<unsigned> ans = std::async(boring);

    std::cout << "    Waiting for answer..." << std::endl;

    unsigned result = ans.get();

    std::cout << "    boring answer = " << result << std::endl;
    std::cout << "--- main" << std::endl;

    return 0;
}
