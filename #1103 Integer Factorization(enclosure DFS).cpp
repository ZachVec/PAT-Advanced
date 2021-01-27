#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

std::vector<int> partition(int n, int k, int p){
    int maximum = 0, size = int(pow(n, 1.0/p));
    std::vector<int> ans, choice, powTable;
    for(int i = 0; i <= size; ++i) powTable.emplace_back(int(pow(i, p)));
    std::function<void(int, int, int)> DFS = [&](int remain, int nParts, int size){
        if(remain == 0 && nParts == 0) {
            int sum = 0;
            for(const int& i : choice) sum += i;
            if(sum > maximum || (sum == maximum && choice > ans)) maximum = sum, ans = choice;
        }
        else if(remain > 0 && size > 0 && nParts > 0) {
            DFS(remain, nParts, size - 1);
            choice.emplace_back(size);
            DFS(remain - powTable[size], nParts - 1, size);
            choice.pop_back();
        }
    };
    DFS(n, k, size);
    return ans;
}

int main() {
    int n, k, p;
    if(scanf("%d%d%d", &n, &k, &p) != 3) return 0;

    auto ans = partition(n, k, p);
    if(ans.empty()) printf("Impossible");
    else {
        printf("%d", n);
        for(auto it = ans.begin(); it != ans.end(); ++it) printf(" %c %d^%d", it == ans.begin() ? '=' : '+', *it, p);
    }
    putchar('\n');
    return 0;
}