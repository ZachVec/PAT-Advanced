#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
unordered_map<char, unsigned> multiplier{{'T', 9}, {'A', 6}, {'B', 4}};

int main() {
    size_t n;
    if(!scanf("%zu\n", &n)) return 0;

    unsigned score;
    char level, school[7];
    unordered_map<string, pair<unsigned, unsigned>> scores;
    for(size_t i = 0; i < n && scanf("%c%*s %u %s\n", &level, &score, school); ++i) {
        for(char *p = school; *p != 0; ++p) *p = tolower(*p);
        auto &value = scores[school];
        value.first += score * multiplier[level];
        ++value.second;
    }

    typedef tuple<unsigned, unsigned, string> Record;
    vector<Record> ranking;
    for(const auto &kv : scores) ranking.emplace_back(kv.second.first / 6, kv.second.second, kv.first);
    sort(ranking.begin(), ranking.end(), [](const Record &a, const Record &b) {
        return get<0>(a) != get<0>(b) ? get<0>(a) > get<0>(b) : 
               get<1>(a) != get<1>(b) ? get<1>(a) < get<1>(b) : get<2>(a) < get<2>(b);
    });

    score = -1U;
    printf("%zu\n", ranking.size());
    for(size_t i = 0, rank = 0; i < ranking.size(); ++i) {
        const Record &rec = ranking[i];
        if(get<0>(rec) != score) score = get<0>(rec), rank = i + 1;
        printf("%zu %s %u %u\n", rank, get<2>(rec).c_str(), get<0>(rec), get<1>(rec));
    }
    return 0;
}