#include <algorithm>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string tmp = "  2 !";
    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), [](unsigned char c) { return std::isspace(c); }), tmp.end());
    std::cout << tmp << std::endl;
    return 0;
}
