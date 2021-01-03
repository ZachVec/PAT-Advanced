#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<unsigned, bool> Record;
map<string, vector<Record>> records, ans;

double fee(unsigned a, unsigned b, unsigned rate[24]) {
    unsigned ans = 0;
    while(a != b) {
        ans += rate[a/60 % 24];
        ++a;
    }
    return double(ans) / 100;
}

int main() {
    size_t n;
    unsigned M, rate[24];
    for(size_t i = 0; i < 24; ++i) scanf("%u", &rate[i]);
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0; i < n ; ++i) {
        string name, status;
        unsigned d, h, m;
        cin >> name;
        scanf("%u:%u:%u:%u", &M, &d, &h, &m);
        cin >> status;
        records[name].emplace_back(d * 24 * 60 + h * 60 + m, status == "on-line");
    }

    for(auto &kv : records) {
        sort(kv.second.begin(), kv.second.end(), [](const Record &a, const Record &b){
            return a.first < b.first;
        });
        Record pre = {0, false};
        for(const Record &now : kv.second) {
            if(pre.second && !now.second) {
                ans[kv.first].push_back(pre);
                ans[kv.first].push_back(now);
            }
            pre = now;
        }
    }

    for(const auto &kv : ans) {
        double amount = 0, temp;
        printf("%s %02u\n", kv.first.c_str(), M);
        for(size_t i = 0; i < kv.second.size(); i += 2) {
            const Record &pre = kv.second[i], &now = kv.second[i+1];
            printf("%02u:%02u:%02u ", pre.first / 1440, (pre.first / 60) % 24, pre.first % 60);
            printf("%02u:%02u:%02u ", now.first / 1440, (now.first / 60) % 24, now.first % 60);
            printf("%u $%.2f\n", now.first - pre.first, temp = fee(pre.first, now.first, rate));
            amount += temp;
        }
        printf("Total amount: $%.2f\n", amount);
    }
    return 0;
}
/*
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/