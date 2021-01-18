#include <iostream>
int main() {
    std::string a, b, c, d;
    std::cin >> a >> b >> c >> d;
    char mp[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    auto inRange = [](char a, char b, char c) { return a <= c && c <= b; };
    for(size_t i = 0, cnt = 0; i < a.size() && i < b.size() && cnt < 2; ++i) {
        if(a[i] != b[i] || !isalnum(a[i])) continue;
        if(cnt == 0 && inRange('A', 'G', a[i])) {
            printf("%s ", mp[size_t(a[i]-'A')]);
            ++cnt;
        }
        else if(cnt == 1 && (inRange('A', 'N', a[i]) || isdigit(a[i]))){
            printf("%02u:", isdigit(a[i]) ? unsigned(a[i] - '0') : unsigned(a[i] - 'A' + 10));
            ++cnt;
        }
    }
    for(size_t i = 0; i < c.size() && d.size(); ++i) {
        if(c[i] != d[i] || !isalpha(c[i])) continue;
        printf("%02zu\n", i);
    }
    return 0;
}