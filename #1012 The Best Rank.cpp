#include <iostream>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
typedef struct Student{
    unsigned id, grade[4];
} Stu;
typedef pair<size_t, unsigned> Rank;
Student stus[2000];
unordered_map<unsigned, Rank> ranking;

int main() {
    size_t n, m;
    char mapping[4] = {'A', 'C', 'M', 'E'};
    if(scanf("%zu%zu", &n, &m) == EOF) return 0;
    for(size_t i = 0; i < n; ++i) {
        Student &s = stus[i];
        scanf("%u%u%u%u", &s.id, &s.grade[1], &s.grade[2], &s.grade[3]);
        s.grade[0] = (s.grade[1] + s.grade[2] + s.grade[3]) / 3;
    }
    for(size_t sub = 0; sub < 4; ++sub) {
        sort(stus, stus + n, [sub](const Stu &a, const Stu &b)
            { return a.grade[sub] > b.grade[sub]; });
        unsigned rank = 0, grade = 101;
        for(size_t i = 0; i < n; ++i) {
            const Stu &s = stus[i];
            if(s.grade[sub] < grade) {
                rank = i + 1;
                grade = s.grade[sub];
            }
            if(rank < ranking[s.id].second || ranking[s.id].second == 0)
                ranking[s.id] = {sub, rank};
        }
    }
    unsigned query;
    for(size_t i = 0; i < m && scanf("%u", &query); ++i) {
        if(!ranking.count(query)) printf("N/A\n");
        else {
            printf("%u %c\n", ranking[query].second, mapping[ranking[query].first]);
        }
    }
    return 0;
}
/*
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

1 C
1 M
1 E
1 A
3 A
N/A
*/