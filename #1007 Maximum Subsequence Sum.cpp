#include <iostream>

int main() {
    int *nums, *prev, *sums;
    size_t n, ans = 0;
    bool allNeg = true;
    
    if(scanf("%zu", &n) == EOF || n == 0) return 0;
    nums = new int[n];
    prev = new int[n];
    sums = new int[n];
    for(size_t i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
        sums[i] = prev[i] = nums[i];
        allNeg = allNeg && (nums[i] < 0);  
    }
    
    if(allNeg) {
        printf("0 %d %d\n", nums[0], nums[n-1]);
        return 0;
    }
    
    for(size_t i = 1; i < n; ++i) {
        if(sums[i-1] >= 0) {
            prev[i] =  prev[i-1];
            sums[i] += sums[i-1];
        }
    }
    
    for(size_t i = 1; i < n; ++i) 
        if(sums[i] > sums[ans])  ans = i;
    
    printf("%d %d %d\n", sums[ans], prev[ans], nums[ans]);
    delete[] nums;
    delete[] prev;
    delete[] sums;
    return 0;
}
/*
10
-10 1 2 3 4 -5 -23 3 7 -21

10 1 4
*/