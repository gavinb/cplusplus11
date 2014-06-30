/*
  range-based for example:

  sums up all the numbers passed in as arguments on the command line
 */

#include <vector>
#include <iostream>

#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

int main(int argc, char* argv[])
{
    // Setup vector with numbers passed in

    std::vector<int>  vec;

    for (int i = 1; i < argc; i++)
    {
        vec.push_back(std::stoi(argv[i]));
    }

    // Old style iterator-based for loop
    {
        long int total = 0;

        std::vector<int>::iterator it;
        for (it = vec.begin(); it != vec.end(); ++it)
        {
            int& n = *it;
            total += n;
        }

        std::cout << "Total: " << total << std::endl;
    }

    // Boost foreach
    {
        long int total = 0;

        foreach (int& n, vec)
        {
            total += n;
        }

        std::cout << "Total: " << total << std::endl;
    }

    // New range-based for loop
    {
        long int total = 0;

        for (auto n : vec)
        {
            total += n;
        }

        std::cout << "Total: " << total << std::endl;
    }

    return 0;
}
