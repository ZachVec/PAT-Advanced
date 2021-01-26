#include<iostream>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;
char i2s[2][13][5] = {
    {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
    {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}    
};
unordered_map<string, int> s2i[2];

int main() {
    size_t n; string str; 
    if(!scanf("%zu\n", &n)) return 0;
    for(size_t i = 0; i < 2; ++i) {
        for(size_t j = 0; j < 13; ++j) {
            s2i[i][i2s[i][j]] = j;
        }
    }
    for(size_t i = 0; i < n && getline(cin, str); ++i) { 
        if(isdigit(str.front())) {
            int temp = stoi(str);
            if(temp < 13 || temp % 13 == 0) printf("%s\n", temp < 13 ? i2s[0][temp] : i2s[1][temp / 13]);
            else printf("%s %s\n", i2s[1][temp / 13], i2s[0][temp % 13]);
        }
        else {
            vector<string> temp;
            for(istringstream line(str); line >> str; temp.emplace_back(str));
            if(temp.size() == 2) printf("%d\n", s2i[1][temp.front()] * 13 + s2i[0][temp.back()]);
            else printf("%d\n", s2i[0].count(temp.front()) ? s2i[0][temp.front()] : s2i[1][temp.front()] * 13);
        }
    }
    return 0;
}