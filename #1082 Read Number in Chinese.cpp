#include <iostream>
#include <vector>
char mapping[10][6]  = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char unit[4][6]      = {"", " Shi", " Bai", " Qian"};
char groupUnit[3][6] = {"", " Wan", " Yi"};

int main() {
    int num;
    std::vector<size_t> digits;
    if(!scanf("%d", &num)) return 0;
    if(num < 0) printf("Fu ");
    else if(num == 0) printf("ling");
    for(int n = std::abs(num); n != 0; n /= 10) digits.emplace_back(n % 10);
    
    bool hasZero = false, output = false;
    for(size_t i = digits.size() - 1; i < digits.size(); --i) {
        if(digits[i] == 0) hasZero = true;
        else {
            if(i != digits.size() - 1) putchar(' ');
            if(hasZero) printf("ling ");
            printf("%s%s", mapping[digits[i]], unit[i % 4]);
            hasZero = false; output = true;
        }
        if(i % 4 == 0 && output) {
            output = false;
            printf("%s", groupUnit[i / 4]);
        }
    }
    putchar('\n');
    return 0;
}
/*
1. 除了第一位之前不输出空格，其他都要输出空格
2. 两个数之间如果有0，则要输出“ling”
3. 每一个小组之间都要输出小组的单位
*/