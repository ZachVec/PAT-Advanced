#include <iostream>
#include <vector>
using namespace std;
typedef pair<size_t, bool> Statements;

int main() {
    size_t n;
    if(!scanf("%zu\n", &n)) return 0;

    char sign;
    vector<Statements> said(n+1);
    vector<bool> guess(n+1, false);
    for(size_t i = 1, index; i <= n && scanf("%c%zu\n", &sign, &index); ++i) {
        said[i] = {index, sign == '-'};
    }
    vector<size_t> liars;
    for(size_t werewolf1 = 1; werewolf1 <= n; guess[werewolf1++] = false) {
        guess[werewolf1] = true;
        for(size_t werewolf2 = werewolf1 + 1; werewolf2 <= n; guess[werewolf2++] = false) {
            guess[werewolf2] = true; liars.clear();
            for(size_t k = 1; k <= n; ++k) {
                if(said[k].second == guess[said[k].first]) continue;
                liars.emplace_back(k);
            }
            if(liars.size() == 2 && guess[liars.front()] != guess[liars.back()]) {
                printf("%zu %zu\n", werewolf1, werewolf2);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}