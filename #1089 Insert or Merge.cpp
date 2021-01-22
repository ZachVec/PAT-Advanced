#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    size_t n, idx1, idx2;
    if(!scanf("%zu", &n)) return 0;
    vector<int> ori(n), aft(n);
    for(int &i : ori)  if(!scanf("%d", &i)) return 0;
    for(int &i : aft) if(!scanf("%d", &i)) return 0;
    for(idx1 = 1; idx1 < n && aft[idx1-1] <= aft[idx1]; ++idx1);
    for(idx2 = idx1; idx2 < n && ori[idx2] == aft[idx2]; ++idx2);
    if(idx2 == n) {
        printf("Insertion Sort\n");
        sort(ori.begin(), ori.begin() + idx1 + 1);
    }
    else {
        printf("Merge Sort\n");
        bool flag = false;
        for(size_t len = 2; len <= n && !flag; len *= 2) {
            flag = ori == aft;
            for(size_t i = 0, j = len; i < n; i = j, j += len) {
                sort(ori.begin() + i, min(ori.begin() + j, ori.end()));
            }
        }
    }
    for(size_t i = 0; i < n; ++i) printf("%d%c", ori[i], " \n"[i == n-1]);
    return 0;
}