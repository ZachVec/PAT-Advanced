#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    size_t m, n, s; 
    if(scanf("%zu%zu%zu", &m, &n, &s) != 3) return 0;
    
    string name;
    unordered_set<string> winners;
    for(size_t i = 1; i <= m && cin >> name; ++i) {
        if(i != s) continue;
        if(winners.count(name)) s = s + 1;
        else {
            printf("%s\n", name.c_str());
            winners.insert(name);
            s += n;
        }
    }
    if(winners.empty()) printf("Keep going...\n");
    return 0;
}