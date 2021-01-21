#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<bool> hashTable(256, false);
    for(const char &ch : b) hashTable[isalpha(ch) ? toupper(ch) : ch] = true;
    for(const char &ch : a) {
        size_t idx = isalpha(ch) ? toupper(ch) : ch;
        if(!hashTable[idx]) {
            putchar(toupper(ch));
            hashTable[idx] = true;
        }
    }
    putchar('\n');
    return 0;
}