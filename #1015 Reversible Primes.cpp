#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    for(unsigned i = 2, upper = sqrt(num); i <= upper; ++i) {
        if(num % i == 0) return false;
    }
    return true;
}

int revInRadix(int n, int radix){
    int ret = 0;
    vector<int> rev;
    for(int num = n; num != 0 || rev.empty(); num /= radix) 
        rev.push_back(num % radix);
    for(const int &i : rev) ret = ret * radix + i;
    return ret;
}

int main() {
    int n, radix;
    while(scanf("%d", &n) && n >= 0) {
        scanf("%d", &radix);
        if(isPrime(n) && isPrime(revInRadix(n, radix))) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
73 10
23 2
23 10
-2

Yes
Yes
No
*/