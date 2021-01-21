#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef size_t UID, SchoolID, Grade, Quota;
typedef pair<Grade, Grade> Score;  // ge, totalScore
typedef pair<Quota, vector<UID>> School; // quota > 0, admitted UIDs
typedef vector<SchoolID> DreamSchools;

int main() {
    size_t n, m, k; // n - #Applicants, m - #schools, k - #dreamSchools
    if(scanf("%zu%zu%zu", &n, &m, &k) != 3) return 0;

    vector<UID>                   uids;           // Applicants' IDs, which need to be sorted 
    vector<Score>                 scores;         // Applicants' Scores, on which the sort base
    vector<School>                schools(m);     // Applicants' info, including quota and admitted UID
    vector<DreamSchools>          dreamSchools(n, DreamSchools(k)); // dream schools of each applicant
    for(School &s : schools) if(!scanf("%zu", &s.first)) return 0;
    for(size_t i = 0, ge, gi; i < n && scanf("%zu%zu", &ge, &gi); ++i) {
        uids.emplace_back(i); scores.emplace_back(ge + gi, ge);
        for(SchoolID &id : dreamSchools[i]) if(!scanf("%zu", &id)) return 0;
    }

    sort(uids.begin(), uids.end(), [&scores](const UID &a, const UID &b) { return scores[a] > scores[b]; });
    for(const UID &uid : uids) {
        for(const SchoolID &schoolid : dreamSchools[uid]) {
            Quota       &quota = schools[schoolid].first;
            vector<UID> &admit = schools[schoolid].second;
            if(admit.size() < quota || scores[admit.back()] == scores[uid]){
                admit.emplace_back(uid); break;
            }
        }
    }

    for(School &school : schools) {
        vector<UID> &admit = school.second;
        sort(admit.begin(), admit.end());
        for(size_t i = 0; i < admit.size(); ++i) printf("%zu%c", admit[i], " \n"[i == admit.size() - 1]);
        if(admit.empty()) putchar('\n');
    }
    return 0;
}