#include <iostream>

int main() {
    std::string str;
    bool *skip = new bool[256]();
    getline(std::cin, str);
    for(char ch = getchar(); ch != '\n'; ch = getchar())
        skip[size_t(ch)] = true;
    for(const char ch : str) 
        if(!skip[size_t(ch)]) putchar(ch);
    putchar('\n');
    delete[] skip;
    return 0;
}