#include <iostream>
#include <queue>
#include <array>
using namespace std;
typedef pair<size_t,   unsigned> Table, tInfo;   // idx, endTime; isVip, cnt;
typedef pair<unsigned, unsigned> Player;  // lastTime, arriveTime
template<typename Type> using CMP = bool (*)(const Type &a, const Type &b);
template<typename Type> using Queue = priority_queue<Type, vector<Type>, CMP<Type>>;
template<typename Type> inline bool more(const Type &a, const Type &b) { 
    return a.second == b.second ? a.first > b.first : a.second > b.second; };

int main() {
    size_t n, m, k;
    array<Queue<Table>,  2> tables {Queue<Table>(more),  Queue<Table>(more)};
    array<Queue<Player>, 2> players{Queue<Player>(more), Queue<Player>(more)};
    if(scanf("%zu", &n) == EOF || n == 0) return 0;
    for(size_t i = 0, isVip; i < n; ++i) {
        unsigned H, M, S, playTime;
        if(scanf("%u:%u:%u %u %zu", &H, &M, &S, &playTime, &isVip) != 5) return 0;
        players[isVip].emplace(60 * (playTime < 120 ? playTime : 120), H * 3600 + M * 60 + S);
    }
    if(scanf("%zu%zu", &m, &k) == EOF || m == 0) return 0;
    vector<tInfo> tableInfo(m, {0, 0});
    for(size_t i = 0, idx; i < k && scanf("%zu", &idx); ++i) tableInfo[idx-1].first = 1;
    for(size_t i = 0; i < m; ++i) tables[tableInfo[i].first].emplace(i, 28800);

    for(size_t i = 0, tidx, pidx; i < n; ++i) {
        if(tables[0].empty()  || tables[1].empty())  tidx = tables[1].empty()  ? 0 : 1;
        else tidx = !more(tables[0].top(),  tables[1].top())  ? 0 : 1;
        if(players[0].empty() || players[1].empty()) pidx = players[1].empty() ? 0 : 1;
        else pidx = !more(players[0].top(), players[1].top()) ? 0 : 1;

        if(tidx == 1 && pidx == 0) {
            if(!players[1].empty() && players[1].top().second <= tables[1].top().second) pidx = 1;
        }
        else if(tidx == 0 && pidx == 1){
            if(!tables[1].empty()  && tables[1].top().second <= players[1].top().second) tidx = 1;
        }

        unsigned arvTime = players[pidx].top().second;
        unsigned srvTime = max(players[pidx].top().second, tables[tidx].top().second);
        if(srvTime >= 75600) break;
        printf("%02u:%02u:%02u ", arvTime / 3600, arvTime / 60 % 60, arvTime % 60);
        printf("%02u:%02u:%02u ", srvTime / 3600, srvTime / 60 % 60, srvTime % 60);
        printf("%u\n", unsigned(double(srvTime - arvTime + 30) / 60));
        ++tableInfo[tables[tidx].top().first].second;  // ++cnt
        tables[tidx].emplace(tables[tidx].top().first, srvTime + players[pidx].top().first);
        tables[tidx].pop(); players[pidx].pop();
    }
    for(size_t i = 0; i < tableInfo.size(); ++i)
        printf("%u%c", tableInfo[i].second, " \n"[i == tableInfo.size() - 1]);
    return 0;
}