#include <iostream>
#include <algorithm>
#include <cstring>
constexpr size_t MAXN = 100001;
char names[MAXN][9];
unsigned ages[MAXN];
int netWorth[MAXN];
size_t indices[MAXN];

int main() {
    size_t n, m;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;
    for(size_t i = 0; i < n && scanf("%s%u%d", names[i], &ages[i], &netWorth[i]); ++i) {
        indices[i] = i;
    }
    std::sort(indices, indices + n, [](const size_t a, const size_t b){
        return netWorth[a] != netWorth[b] ? netWorth[a] > netWorth[b] :
               ages[a]     != ages[b]     ? ages[a] < ages[b]         :
               strcmp(names[a], names[b]) < 0;
    });

    unsigned ageL, ageH;
    for(size_t i = 1, k; i <= m && scanf("%zu%u%u", &k, &ageL, &ageH); ++i) {
        size_t cnt = 0;
        printf("Case #%zu:\n", i);
        for(size_t j = 0, idx; j < n && cnt < k; ++j) {
            idx = indices[j];
            if(ageL <= ages[idx] && ages[idx] <= ageH) {
                printf("%s %u %d\n", names[idx], ages[idx], netWorth[idx]);
                ++cnt;
            }
        }
        if(cnt == 0) printf("None\n");
    }
    return 0;
}