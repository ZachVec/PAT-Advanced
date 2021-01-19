#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<unsigned, unsigned, size_t> Info; // score, cnt, idx

int main() {
    size_t n, k, m; // n - #users, k - #questions, m - #submisions
    if(scanf("%zu%zu%zu", &n, &k, &m) != 3) return 0;
    unsigned temp;
    vector<unsigned> fullMarks;
    for(size_t i = 0; i < k && scanf("%u", &temp); ++i) fullMarks.emplace_back(temp);

    vector<bool> disp(n, false);
    vector<vector<unsigned>> grades(n, vector<unsigned>(k, -1));
    for(size_t i = 0, id, qid; i < m && scanf("%zu%zu%u", &id, &qid, &temp); ++i) {
        --id; --qid;
        if(temp != unsigned(-1)) {
            disp[id] = true;
            grades[id][qid] = grades[id][qid] == unsigned(-1) ? temp : max(grades[id][qid], temp);
        }
        else if(grades[id][qid] == unsigned(-1)) grades[id][qid] = 0;
    }

    vector<Info> ans;
    for(size_t i = 0; i < n; ++i) {
        if(!disp[i]) continue;
        unsigned cnt = 0, score = 0;
        for(size_t j = 0; j < k; ++j) {
            if(grades[i][j] == fullMarks[j]) ++cnt;
            if(grades[i][j] != unsigned(-1)) score += grades[i][j];
        }
        ans.emplace_back(score, cnt, i);
    }
    sort(ans.begin(), ans.end(), [](const Info &a, const Info &b){
        return get<0>(a) != get<0>(b) ? get<0>(a) > get<0>(b) :
               get<1>(a) != get<1>(b) ? get<1>(a) > get<1>(b) :
               get<2>(a) < get<2>(b);
    });

    unsigned rank = 1, score = get<0>(ans.front());
    for(size_t i = 0, idx; i < ans.size(); ++i) {
        if(score != get<0>(ans[i])) {
            rank = i + 1;
            score = get<0>(ans[i]);
        }
        printf("%u %05zu %u", rank, (idx = get<2>(ans[i])) + 1, get<0>(ans[i]));
        for(const unsigned &grade : grades[idx]) {
            if(grade == unsigned(-1)) printf(" -");
            else printf(" %u", grade);
        }
        putchar('\n');
    }
    return 0;
}