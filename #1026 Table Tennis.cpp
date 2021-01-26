#include <iostream>
#include <queue>
using namespace std;
typedef pair<unsigned,   size_t> Table, tInfo;   // endTime, idx; cnt, isVip;
typedef pair<unsigned, unsigned> Player;  // arriveTime, PlayTime
template<typename Type> using Queue = priority_queue<Type, vector<Type>, greater<Type>>;

int main() {
    size_t n, m, k;
    Queue<Table>  tables[2];
    Queue<Player> players[2];

    if(!scanf("%zu", &n) || n == 0) return 0;
    unsigned H, M, S, playTime, srvTime;
    for(size_t i = 0, isVip; i < n && scanf("%u:%u:%u %u %zu", &H, &M, &S, &playTime, &isVip) == 5; ++i) {
        players[isVip].emplace(H * 3600 + M * 60 + S, 60 * (playTime < 120 ? playTime : 120));
    }
    if(scanf("%zu%zu", &m, &k) != 2 || m == 0) return 0;
    vector<tInfo> infos(m, {0, 0});
    for(size_t i = 0, idx; i < k && scanf("%zu", &idx); ++i) infos[idx-1].second = 1;
    for(size_t i = 0; i < m; ++i) tables[infos[i].second].emplace(28800, i);

    for(size_t i = 0, tVip, pVip; i < n; ++i) {
        if(tables[0].empty()  || tables[1].empty())  tVip = tables[1].empty()  ? 0 : 1;
        else tVip = tables[0].top() < tables[1].top() ? 0 : 1;
        if(players[0].empty() || players[1].empty()) pVip = players[1].empty() ? 0 : 1;
        else pVip = players[0].top() < players[1].top() ? 0 : 1;
        // adjust
        if(tVip == 1 && pVip == 0) {
            if(!players[1].empty() && players[1].top().first <= tables[1].top().first) pVip = 1;
        }
        else if(tVip == 0 && pVip == 1){
            if(!tables[1].empty()  && tables[1].top().first <= players[1].top().first) tVip = 1;
        }
        // output & update
        const Table  &t = tables[tVip].top(); 
        const Player &p = players[pVip].top();
        if((srvTime = max(p.first, t.first)) >= 75600) break;
        printf("%02u:%02u:%02u ", p.first / 3600, p.first / 60 % 60, p.first % 60);
        printf("%02u:%02u:%02u ", srvTime / 3600, srvTime / 60 % 60, srvTime % 60);
        printf("%u\n", unsigned(double(srvTime - p.first + 30) / 60));
        ++infos[t.second].first; tables[tVip].emplace(srvTime + p.second, t.second);
        tables[tVip].pop(); players[pVip].pop();
    }
    for(size_t i = 0; i < infos.size(); ++i) printf("%u%c", infos[i].first, " \n"[i == infos.size() - 1]);
    return 0;
}