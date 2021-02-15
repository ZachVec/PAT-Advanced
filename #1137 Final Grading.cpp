#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct Grade{
    int opa, mid, fin, gpa;
    Grade() : opa(-1), mid(-1), fin(-1), gpa(-1){}
};

int main() {
    int score;
    size_t p, m, n;
    unordered_map<string, Grade> mp;
    vector<pair<string, Grade>> res;
    if(scanf("%zu%zu%zu", &p, &m, &n) != 3) return 0;
    for(string name; p-- && cin >> name >> score; mp[name].opa = score);
    for(string name; m-- && cin >> name >> score; mp[name].mid = score);
    for(string name; n-- && cin >> name >> score; mp[name].fin = score);
    for(auto &kv : mp) kv.second.gpa = 0.5 + (kv.second.mid > kv.second.fin ? 0.4 * double(kv.second.mid) + 0.6 * double(kv.second.fin) : kv.second.fin);
    for(const auto &kv : mp) {
        if(kv.second.opa < 200 || kv.second.gpa < 60) continue;
        res.emplace_back(kv.first, kv.second);
    }
    sort(res.begin(), res.end(), [](const pair<string, Grade> &a, const pair<string, Grade> &b) {
        return a.second.gpa != b.second.gpa ? a.second.gpa > b.second.gpa : a.first < b.first;
    });
    for(const auto &kv : res) printf("%s %d %d %d %d\n", kv.first.c_str(), kv.second.opa, kv.second.mid, kv.second.fin, kv.second.gpa);
    return 0;
}