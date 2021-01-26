#include <iostream>
#include <vector>
using namespace std;
int main() {
    string shopKeeper, eva;
    cin >> shopKeeper >> eva;
    vector<int> hashTable(256, 0);
    for(const char &color : shopKeeper) ++hashTable[color];
    for(const char &color : eva)        --hashTable[color];
    int ans = 0;
    for(const int &cnt : hashTable) if(cnt < 0) ans -= cnt;
    if(ans) printf("No %d\n", ans);
    else printf("Yes %zu\n", shopKeeper.size() - eva.size());
    return 0;
}