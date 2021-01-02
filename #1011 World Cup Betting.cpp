#include <iostream>
#include <utility>
typedef std::pair<size_t, double> Bet;

int main() {
    Bet bets[3];
    double temp;
    char mapping[3] = {'W', 'T', 'L'};
    for(size_t i = 0; i < 3; ++i) bets[i] = {0, 0.0};
    for(size_t i = 0; i < 3; ++i) {
        for(size_t j = 0; j < 3; ++j) {
            scanf("%lf", &temp);
            if(temp > bets[i].second) 
                bets[i] = {j, temp};
        }
    }
    temp = 1;
    for(size_t i = 0; i < 3; ++i) printf("%c ", mapping[bets[i].first]);
    for(size_t i = 0; i < 3; ++i) temp *= bets[i].second;
    printf("%.2f\n", (temp * 0.65 - 1) * 2);
    return 0;
}
/*
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1

T T W 39.31
*/