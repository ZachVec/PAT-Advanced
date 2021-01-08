#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
    size_t n;
    string account, password;
    vector<pair<string, string>> ans;
    unordered_map<char, char> mp = {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
    if(scanf("%zu", &n) != 1) return 0;
    for(size_t i = 0; i < n && cin >> account >> password; ++i) {
        bool modified = false;
        for(char &ch : password) 
            if(mp.count(ch)) {
                modified = true;
                ch = mp[ch];
            }
        if(modified) ans.emplace_back(account, password);
    }
    if(ans.empty()) {
        printf(n == 1 ? "There is %zu account and no account is modified\n": 
                        "There are %zu accounts and no account is modified\n", n);
    }
    else {
        printf("%zu\n", ans.size());
        for(const auto &kv : ans) printf("%s %s\n", kv.first.c_str(), kv.second.c_str());
    }
    return 0;
}
/* 1 (one) by @, 0 (zero) by %, l by L, and O by o */