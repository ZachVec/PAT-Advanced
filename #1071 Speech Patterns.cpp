#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string str; unsigned maxCnt = 0;
    unordered_map<string, unsigned> cnts;
    for(char ch = getchar(); ch != '\n'; ch = getchar()) {
        if(isalnum(ch)) str += isdigit(ch) ? ch : tolower(ch);
        else if(!str.empty()){
            ++cnts[str];
            str.clear();
        }
    }
    if(!str.empty()) ++cnts[str];
    for(const auto &kv : cnts) {
        if(kv.second > maxCnt) {
            maxCnt = kv.second;
            str = kv.first;
        }
        else if(kv.second == maxCnt && kv.first < str)
            str = kv.first;
    }
    printf("%s %u\n", str.c_str(), maxCnt);
    return 0;
}