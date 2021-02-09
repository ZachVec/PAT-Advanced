#include <iostream>
#include <cstring>

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    char str[11];
    for(size_t i = 0, a, b, number, len; i < n && scanf("%s", str) && (len = strlen(str)); ++i) {
        number = atoi(str); b = atoi(str + len/2); str[len/2] = 0; a = atoi(str);
        printf("%s\n", (a !=0 && b != 0 && number % (a * b) == 0) ? "Yes" : "No");
    }
    return 0;
}