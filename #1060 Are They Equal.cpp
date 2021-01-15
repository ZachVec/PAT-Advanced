#include <iostream>
using namespace std;

ssize_t normalize(string &str, size_t n) {
    while(!str.empty() && str.front() == '0') str.erase(str.begin());
    ssize_t power = str.empty() ? 0 : str.find('.');
    if(!str.empty()) {
        if(str.front() == '.') {  // integer part is 0
            while(!str.empty() && *(str.erase(str.begin())) == '0') --power;
            if(str.empty()) power = 0;
        }
        else {
            if(power == -1) power = str.size();
            else str.erase(power, 1);
        }
    }
    if(str.size() < n) str.insert(str.end(), n - str.size(), '0');
    else if(str.size() > n) str.erase(str.begin() + n, str.end());
    return power;
}

int main() {
    ssize_t n, aPow, bPow;
    string a, b;
    cin >> n >> a >> b;
    if((aPow = normalize(a, n)) == (bPow = normalize(b, n)) && a == b) 
        printf("YES 0.%s*10^%zd\n", a.c_str(), aPow);
    else 
        printf("NO 0.%s*10^%zd 0.%s*10^%zd\n", a.c_str(), aPow, b.c_str(), bPow);
    return 0;
}