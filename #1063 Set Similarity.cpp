#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    size_t n, m;
    unsigned num;
    unordered_set<unsigned> nums[50]; 
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 0, k; i < n && scanf("%zu", &k); ++i) 
        for(size_t j = 0; j < k && scanf("%u", &num); ++j) 
            nums[i].insert(num);
    if(!scanf("%zu", &m)) return 0;
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) {
        size_t total = nums[u-1].size(), sim = 0;
        for(size_t num : nums[v-1]) {
            if(nums[u-1].count(num)) ++sim;
            else ++total;
        }
        printf("%.1f%%\n", 100 * double(sim)/double(total));
    }
    return 0;
}