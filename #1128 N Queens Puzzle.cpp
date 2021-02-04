#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    for(size_t i = 0, k; i < n && scanf("%zu", &k); ++i) {
        // diag1: row + col - 1; diag2: row - col + k
        bool isSolution = true;
        vector<bool> isRowAvail(k+1, true), isDiag1Avail(2*k, true), isDiag2Avail(2*k, true); 
        for(size_t col = 1, row; col <= k && scanf("%zu", &row); ++col) {
            isSolution = isSolution && isRowAvail[row] && isDiag1Avail[row + col - 1] && isDiag2Avail[row + k - col];
            isRowAvail[row] = isDiag1Avail[row + col - 1] = isDiag2Avail[row + k - col] = false;
        }
        printf("%s\n", isSolution ? "YES" : "NO");
    }
    return 0;
}