#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str; cin >> str;

    size_t cnt = 0, ans = 0;
    vector<int> Pcnts(str.size(), 0);
    for(size_t i = 0; i < str.size(); ++i) {
        if(str[i] == 'P') ++cnt;
        else if(str[i] == 'A') Pcnts[i] = cnt;
    }
    cnt = 0;
    for(size_t i = str.size()-1; i < str.size(); --i) {
        if(str[i] == 'T') ++cnt;
        else if(str[i] == 'A') ans += cnt * Pcnts[i];
    }

    printf("%zu\n", ans % 1000000007);
    return 0;
}