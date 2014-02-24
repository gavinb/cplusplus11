/**
    strings_from_numbers.cpp

    Using the new C++11 string conversion support to parse numeric literals.

    by Gavin Baker <gavinb@antonym.org>
 */
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Usage: strings_from_numbers [ilfd] <num>" << std::endl;
        return 1;
    }

    char typ = argv[1][0];

    try
    {
        switch (typ)
        {
            case 'i':
            {
                int as_int = std::stoi(argv[2]);
                std::cout << "as_int = " << as_int << std::endl;
                break;
            }
            case 'l':
            {
                long as_long = std::stol(argv[2]);
                std::cout << "as_long = " << as_long << std::endl;
                break;
            }
            case 'f':
            {
                float as_float = std::stof(argv[2]);
                std::cout << "as_float = " << as_float << std::endl;
                break;
            }
            case 'd':
            {
                double as_double = std::stod(argv[2]);
                std::cout << "as_double = " << as_double << std::endl;
                break;
            }
            default:
                std::cout << "Invalid format character: " << typ << std::endl;
        }
    }
    catch (std::invalid_argument& e)
    {
        std::cout << "Invalid number: " << argv[2] << std::endl;
    }
    return 0;
}
