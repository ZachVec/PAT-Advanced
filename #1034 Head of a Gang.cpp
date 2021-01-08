#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
constexpr size_t MAXN = 2000;
bool visit[MAXN];
unsigned weight[MAXN], graph[MAXN][MAXN];

template<typename Key, typename Value> 
size_t insert(unordered_map<Key, Value> &mp1, unordered_map<Value, Key> &mp2, const Key &k, const Value &v) {
    if(!mp1.count(k)) {
        mp1[k] = v;
        mp2[v] = k;
    }
    return mp1[k];
}

void DFS(size_t src, unsigned &tWeight, unsigned &cnt, size_t &header) {
    visit[src] = true;
    tWeight += weight[src];
    ++cnt;
    if(weight[src] > weight[header]) header = src;
    for(size_t i = 0; i < MAXN; ++i) {
        if(visit[i] || graph[src][i] == 0) continue;
        DFS(i, tWeight, cnt, header);
    }
}

int main() {
    size_t n;
    string a, b;
    unsigned thrhd, time;
    map<string, unsigned> gangInfo;
    unordered_map<string, size_t> s2i;
    unordered_map<size_t, string> i2s;
    
    if(scanf("%zu%u", &n, &thrhd) != 2) return 0;
    for(size_t i = 0, u, v; i < n && cin >> a >> b >> time; ++i) {
        u = insert<string, size_t>(s2i, i2s, a, s2i.size());
        v = insert<string, size_t>(s2i, i2s, b, s2i.size());
        graph[u][v] = (graph[v][u] += time);
        weight[u] += time; weight[v] += time;
    }
    for(auto kv : s2i) {
        if(visit[kv.second]) continue;
        unsigned tWeight = 0, cnt = 0;
        size_t header = kv.second;
        DFS(kv.second, tWeight, cnt, header);
        if(cnt > 2 && tWeight > 2 * thrhd) gangInfo[i2s[header]] = cnt;
    }
    printf("%zu\n", gangInfo.size());
    for(const auto &kv : gangInfo) {
        printf("%s %u\n", kv.first.c_str(), kv.second);
    }
    return 0;
}