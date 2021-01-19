#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, double> Stock;  // weight, unitPrice

int main() {
    size_t n;
    double demandWeight;
    if(scanf("%zu%lf", &n, &demandWeight) != 2) return 0;
    vector<Stock> stocks(n);
    for(Stock &stock : stocks) if(!scanf("%lf", &stock.first)) return 0;
    for(Stock &stock : stocks) if(!scanf("%lf", &stock.second)) return 0;
    for(Stock &stock : stocks) stock.second /= stock.first;
    sort(stocks.begin(), stocks.end(), [](const Stock &a, const Stock &b) {
        return a.second > b.second;
    });
    double ans = 0, sold;
    for(const Stock &stock : stocks) {
        if(demandWeight == 0) break;
        demandWeight -= (sold = min(demandWeight, stock.first));
        ans += sold * stock.second;
    }
    printf("%.2f\n", ans);
    return 0;
}