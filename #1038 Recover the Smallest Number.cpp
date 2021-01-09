#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    size_t n;
    string str;
    vector<string> strs;
    
    if(scanf("%zu", &n) != 1) return 0;
    for(size_t i = 0; i < n && cin >> str; ++i)
        strs.emplace_back(str);

    sort(strs.begin(), strs.end(), [](const string &a, const string &b) {
        return a + b < b + a;
    });

    str = "";
    for(const string &s : strs) str += s;
    while(str.size() > 1 && str.front() == '0') str.erase(str.begin());
    printf("%s\n", str.c_str());
    return 0;
}