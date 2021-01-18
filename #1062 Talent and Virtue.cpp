#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Info{
    size_t id, vg, tg, tier;
};

int main() {
    size_t n, l, h;
    vector<Info> infos;
    if(scanf("%zu%zu%zu", &n, &l, &h) != 3) return 0;
    for(size_t i = 0, id, vg, tg, tier; i < n && scanf("%zu%zu%zu", &id, &vg, &tg); ++i) {
        if(vg < l || tg < l) continue;
        tier = vg >= h ? tg >= h ? 1 : 2 : vg >= tg ? 3 : 4;
        infos.push_back({id, vg, tg, tier});
    }
    sort(infos.begin(), infos.end(), [](const Info &a, const Info &b) {
        return a.tier      != b.tier      ? a.tier < b.tier : 
               a.vg + a.tg != b.vg + b.tg ? a.vg + a.tg > b.vg + b.tg : 
               a.vg        != b.vg        ? a.vg > b.vg : a.id < b.id;
    });
    printf("%zu\n", infos.size());
    for(const Info &info : infos) {
        printf("%08zu %zu %zu\n", info.id, info.vg, info.tg);
    }
    return 0;
}