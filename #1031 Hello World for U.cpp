#include <iostream>

int main() {
    size_t n1, n2, n3;
    std::string str;
    std::getline(std::cin, str);
    n1 = n3 = (str.size() + 2) / 3;
    n2 = str.size() + 2 - n1 - n3;
    for(size_t i = 0; i < n1 - 1; ++i) {
        putchar(str[i]);
        for(size_t j = 0; j < n2 - 2; ++j) putchar(' ');
        putchar(str[str.size() - 1 - i]);
        putchar('\n');
    }
    for(size_t i = n1 - 1; i < n1 + n2 - 1; ++i) putchar(str[i]);
    putchar('\n');
    return 0;
}   