#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<unsigned, unsigned> Costumer;

int main() {
    size_t n, k;
    vector<Costumer> costumers;
    priority_queue<unsigned, vector<unsigned>, greater<unsigned>> q;
    if(scanf("%zu%zu", &n, &k) == EOF) return 0;
    for(size_t i = 0; i < n; ++i) {
        unsigned h, m, s, w, temp;
        scanf("%u:%u:%u%u", &h, &m, &s, &w);
        if((temp = h * 3600 + m * 60 + s) > 61200) continue;
        costumers.emplace_back(temp, w * 60);
    }

    if(costumers.empty()) return 0;
    sort(costumers.begin(), costumers.end(), [](const Costumer &a, const Costumer &b){
        return a.first < b.first;
    });
    for(size_t i = 0; i < k; ++i) q.push(28800); // 8 O'Clock

    unsigned totalWaitTime = 0;
    for(const Costumer& c : costumers) {
        if(c.first >= q.top()) // available when arrive
            q.push(c.first + c.second);
        else {  // not available when arrive
            q.push(q.top() + c.second);
            totalWaitTime += (q.top() - c.first);
        }
        q.pop();
    }
    printf("%.1f\n", double(totalWaitTime) / (60 * double(costumers.size())));
    return 0;
}

/*
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

8.2
*/