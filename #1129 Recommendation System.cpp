#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<unsigned, bool> Status; // occurance, inQueue

int main() {
    size_t n, k;
    if(scanf("%zu%zu", &n, &k) != 2) return 0;

    vector<size_t> recommend;
    vector<Status> status(n+1, {0, false});
    
    auto update = [&recommend, &status, &k](const size_t &product) {
        auto higherPriority = [&status](const size_t &a, const size_t &b) {
            return status[a].first > status[b].first || (status[a].first == status[b].first && a < b);
        };
        ++status[product].first;
        if(recommend.size() < k && !status[product].second) {
            recommend.emplace_back(product);
            status[product].second = true;
        }
        else if(recommend.size() == k && !status[product].second && higherPriority(product, recommend.back())){
            status[product].second = true; 
            status[recommend.back()].second = false; 
            recommend.back() = product;
        }
        sort(recommend.begin(), recommend.end(), higherPriority);
    };
    for(size_t i = 0, product; i < n && scanf("%zu", &product); ++i) {
        if(!recommend.empty()) {
            printf("%zu:", product);
            for(const size_t &item : recommend) printf(" %zu", item);
            putchar('\n');
        }
        update(product);
    }
    return 0;
}