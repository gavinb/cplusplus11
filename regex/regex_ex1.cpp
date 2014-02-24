
#include <iostream>
#include <string>
#include <regex>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout
            << "Usage: <text>\n"
            << "    Matches line starting with a vowel"
            << std::endl;
        return 1;
    }

    std::string s = argv[1];

    bool match = std::regex_match(s, std::regex("[aeiouAEIOU](.*)") );

    if (match)
    {
        std::cout << "match" << std::endl;
    }

    return 0;    
}
