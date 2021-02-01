#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    size_t n, k;
    const char *awards[] = {"Are you kidding?", "Mystery Award", "Minion", "Chocolate", "Checked"};
    if(!scanf("%zu", &n)) return 0;

    auto isPrime = [](size_t number) -> bool {
        if(number == 0 || number == 1) return false;
        for(size_t i = 2, sz = sqrt(number); i <= sz; ++i) {
            if(number % i == 0) return false;
        }
        return true;
    };
    // ranking[id] being 0 if not exist, rank otherwise
    vector<size_t> awardId(10000, 0);
    for(size_t rank = 1, id; rank <= n && scanf("%zu", &id); ++rank) {
        if(rank == 1) awardId[id] = 1;
        else awardId[id] = isPrime(rank) ? 2 : 3;
    }

    if(!scanf("%zu", &k)) return 0;
    for(size_t i = 0, id; i < k && scanf("%zu", &id); ++i) {
        printf("%04zu: %s\n", id, awards[awardId[id]]);
        if(awardId[id]) awardId[id] = 4; // if won a prize, then modify award to "Checked"
    }
    return 0;
}