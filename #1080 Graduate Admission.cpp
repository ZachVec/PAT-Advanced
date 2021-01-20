#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<size_t, size_t> Score;  // ge, totalScore
typedef pair<size_t, vector<size_t>> School; // quota > 0, ids
typedef vector<size_t> DreamSchool, StuIDS, Admit;

int main() {
    size_t n, m, k; // n - #Students, m - #schools, k - #dreamSchools
    if(scanf("%zu%zu%zu", &n, &m, &k) != 3) return 0;

    vector<School> schools(m);
    for(School &s : schools) if(!scanf("%zu", &s.first)) return 0;

    StuIDS ids;
    vector<Score> scores;
    vector<DreamSchool> dreamSchools(n);
    for(size_t i = 0, ge, gi; i < n && scanf("%zu%zu", &ge, &gi); ++i) {
        ids.emplace_back(i); scores.emplace_back(ge, ge + gi);
        for(size_t j = 0, id; j < k && scanf("%zu", &id); ++j) dreamSchools[i].emplace_back(id);
    }

    sort(ids.begin(), ids.end(), [&scores](const size_t &a, const size_t &b) {
        return scores[a].second != scores[b].second ? 
               scores[a].second >  scores[b].second : 
               scores[a].first  >  scores[b].first  ;
    });

    for(const size_t &stuId : ids) {
        for(const size_t &schId : dreamSchools[stuId]) {
            size_t &quota = schools[schId].first;
            Admit  &admit = schools[schId].second;
            if(admit.size() < quota || scores[admit.back()] == scores[stuId]){
                admit.emplace_back(stuId); break;
            }
        }
    }

    for(School &school : schools) {
        Admit &admit = school.second;
        sort(admit.begin(), admit.end());
        if(!admit.empty()) printf("%zu", admit.front());
        for(auto it = admit.begin() + 1; it < admit.end(); ++it) printf(" %zu", *it);
        putchar('\n');
    }
    return 0;
}