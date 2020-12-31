#include <iostream>

char mapping[10][10] = {
    "zero", "one", "two", "three",
    "four", "five", "six",
    "seven", "eight", "nine"
};

int main() {
    unsigned rawAns = 0, temp;
    size_t ans[4], sz = 0;
    while(scanf("%1u", &temp) != EOF) rawAns += temp;
    do{
        ans[sz++] = rawAns % 10;
        rawAns /= 10;
    }
    while(rawAns != 0);
    for(--sz; sz != 0; --sz) {
        printf("%s ", mapping[ans[sz]]);
    }
    printf("%s\n", mapping[ans[sz]]);
    return 0;
}

/* input
12345
*/