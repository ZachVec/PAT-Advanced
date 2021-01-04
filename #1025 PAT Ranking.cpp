#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef unsigned long long BigInt;
typedef tuple<BigInt, unsigned, unsigned, unsigned, unsigned> Testee;
// id, score, location, final_rank, local_rank
int main() {
    size_t n;
    vector<Testee> testees;
    auto cmp = [](Testee &a, Testee &b) {
        return get<1>(a) == get<1>(b) ? get<0>(a) < get<0>(b) : get<1>(a) > get<1>(b);
    };

    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 1, m, s; i <= n && scanf("%zu", &m); ++i) {
        s = testees.size();
        for(size_t j = 0; j < m; ++j) {
            BigInt id;
            unsigned score;
            scanf("%llu%u", &id, &score);
            testees.emplace_back(id, score, i, 0, 0);
        }
        sort(&testees[s], &testees[s] + m, cmp);
        unsigned rank = 0, score = 101;
        for(size_t j = s; j < testees.size(); ++j) {
            Testee &t = testees[j];
            if(get<1>(t) < score) {
                score = get<1>(t);
                rank  = get<4>(t) = j - s + 1;
            }
            else get<4>(t) = rank;
        }
    }

    sort(testees.begin(), testees.end(), cmp);
    unsigned rank = 0, score = 101;
    for(size_t i = 0; i < testees.size(); ++i) {
        Testee &t = testees[i];
        if(get<1>(t) < score) {
            score = get<1>(t);
            rank  = get<3>(t) = i + 1;
        }
        else get<3>(t) = rank;
    }
    printf("%zu\n", testees.size());
    for(const Testee t : testees) {
        printf("%013llu %u %u %u\n", get<0>(t), get<3>(t), get<2>(t), get<4>(t));
    }
    return 0;
}
/*
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

registration_number final_rank location_number local_rank
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/