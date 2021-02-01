#include <iostream>
#include <set>

int main() {
    size_t n;
    std::set<unsigned> friendId;
    if(!scanf("%zu", &n)) return 0;
    for(unsigned number, digitSum; n-- && scanf("%u", &number); friendId.insert(digitSum)) {
        for(digitSum = 0; number != 0; number /= 10) digitSum += number % 10;
    }
    printf("%zu", friendId.size());
    for(auto it = friendId.begin(); it != friendId.end(); ++it) printf("%c%u", " \n"[it == friendId.begin()], *it); 
    putchar('\n');
    return 0;
}