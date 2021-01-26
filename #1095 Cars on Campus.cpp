#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef tuple<string, unsigned, bool> Record;
typedef pair<unsigned, bool> noPlateRecord;

int main() {
    size_t n, k;
    if(scanf("%zu%zu", &n, &k) != 2) return 0;

    string plate, in;
    unsigned h, m, s;
    vector<Record> records;
    for(size_t i = 0; i < n && cin >> plate && scanf("%u:%u:%u", &h, &m, &s) && cin >> in; ++i) {
        records.emplace_back(plate, h * 3600 + m * 60 + s, in == "in");
    }
    
    sort(records.begin(), records.end(), less<Record>());
    vector<noPlateRecord> valid;
    unordered_map<string, unsigned> parktime;
    for(auto it = records.begin(); it != records.end() - 1; ++it) {
        if(!get<2>(*it) || get<2>(*it) == get<2>(*(it+1)) || get<0>(*it) != get<0>(*(it+1))) continue;
        valid.emplace_back(get<1>(*it), get<2>(*it));
        valid.emplace_back(get<1>(*(it+1)), get<2>(*(it+1)));
        parktime[get<0>(*it)] += get<1>(*(it+1)) - get<1>(*it);
    }
    
    sort(valid.begin(), valid.end(), [](const noPlateRecord &a, const noPlateRecord &b){ return a.first < b.first; });
    for(size_t i = 0, j = 0, cnt = 0; i < k && scanf("%u:%u:%u", &h, &m, &s); ++i) {
        for(unsigned ts = h * 3600 + m * 60 + s; j < valid.size() && valid[j].first <= ts; ++j) {
            cnt += (valid[j].second ? 1 : -1);
        }
        printf("%zu\n", cnt);
    }

    pair<unsigned, vector<string>> maxParkTime;
    for(const auto &kv : parktime) {
        if(kv.second > maxParkTime.first) {
            maxParkTime.first = kv.second;
            maxParkTime.second.clear();
            maxParkTime.second.emplace_back(kv.first);
        }
        else if(kv.second == maxParkTime.first) maxParkTime.second.emplace_back(kv.first);
    }

    sort(maxParkTime.second.begin(), maxParkTime.second.end());
    for(const auto &plate : maxParkTime.second) printf("%s ", plate.c_str());
    printf("%02u:%02u:%02u\n", maxParkTime.first / 3600, maxParkTime.first / 60 % 60, maxParkTime.first % 60);
    return 0;
}