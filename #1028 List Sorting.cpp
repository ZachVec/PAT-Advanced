#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;
typedef tuple<unsigned, string, unsigned> Record;

int main() {
    size_t n, t;
    if(scanf("%zu%zu", &n, &t) == EOF) return 0;
    vector<Record> rec(n);
    for(Record &r : rec) cin >> get<0>(r) >> get<1>(r) >> get<2>(r);
    sort(rec.begin(), rec.end(), [t](const Record &a, const Record &b) {
        if(t == 2 && get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        if(t == 3 && get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
        return get<0>(a) < get<0>(b);
    });
    for(const Record &r : rec) {
        printf("%06u %s %u\n", get<0>(r), get<1>(r).c_str(), get<2>(r));
    }
    return 0;
}