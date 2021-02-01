#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    size_t n, day;
    if(!scanf("%zu", &n)) return 0;

    vector<unsigned> distance(n);
    for(size_t i = 0; i < n && scanf("%u", &distance[i]); ++i);
    
    sort(distance.begin(), distance.end(), greater<unsigned>());
    for(day = 0; day < distance.size() && day + 1 < distance[day]; ++day);
    printf("%zu\n", day);
    return 0;
}