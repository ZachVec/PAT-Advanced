#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef std::pair<int, std::vector<int>> Ans;
std::vector<int> powTable;

void DFS(std::vector<int> &choice, Ans &ans, int remain, int size, int cnt) {
    if(remain == 0 && cnt == 0){
        int sum = 0;
        for(const int &i : choice) sum += i;
        if(sum > ans.first || (sum == ans.first && choice > ans.second)) ans = {sum, choice}; 
    }
    else if(remain > 0 && size > 0 && cnt > 0){
        DFS(choice, ans, remain, size - 1, cnt);
        choice.emplace_back(size);
        DFS(choice, ans, remain - powTable[size], size, cnt - 1);
        choice.pop_back();
    }
}

int main() {
    int n, k, p;
    if(scanf("%d%d%d", &n, &k, &p) != 3) return 0;

    Ans ans;
    std::vector<int> temp;
    for(int i = 0, limit = int(pow(n, 1.0/p)) + 1; i <= limit; ++i) powTable.emplace_back(int(pow(i, p)));
    DFS(temp, ans, n, int(pow(n, 1.0/p)) + 1, k);
    if(ans.second.empty()) printf("Impossible");
    else {
        printf("%d", n);
        for(auto it = ans.second.begin(); it != ans.second.end(); ++it) 
            printf(" %c %d^%d", it == ans.second.begin() ? '=' : '+', *it, p);
    }
    putchar('\n');
    return 0;
}