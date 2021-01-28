#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    vector<size_t> rootOfhobby(1001, 0), parent(n+1);
    vector<vector<size_t>> hobbies(n+1);
    for(size_t i = 1, k; i <= n && scanf("%zu: ", &k); ++i) {
        for(size_t j = 0, hobby; j < k && scanf("%zu", &hobby); ++j){
            if(!rootOfhobby[hobby]) rootOfhobby[hobby] = i;
            hobbies[i].emplace_back(hobby);
        }
        parent[i] = i;
    }

    auto Find  = [&parent](const size_t &id){
        size_t root; vector<size_t> path;
        for(root = id; parent[root] != root; root = parent[root]) path.emplace_back(root);
        for(const size_t &id : path) parent[id] = root;
        return root;
    };

    auto Union = [&parent, &Find](const size_t &a, const size_t &b) {
        size_t rootOfa = Find(a), rootOfb = Find(b);
        if(rootOfa != rootOfb) parent[rootOfb] = rootOfa;
    };

    for(size_t id = 1; id <= n; ++id) {
        for(const size_t hobby : hobbies[id]) Union(id, Find(rootOfhobby[hobby]));
    }

    vector<unsigned> cntOfEachClusters(n+1, 0), count;
    for(size_t id = 1; id <= n; ++id) ++cntOfEachClusters[Find(id)];
    for(const unsigned &cnt : cntOfEachClusters) if(cnt) count.emplace_back(cnt);
    sort(count.begin(), count.end(), greater<unsigned>());
    printf("%zu\n", count.size());
    for(size_t i = 0; i < count.size(); ++i) printf("%u%c", count[i], " \n"[i == count.size()-1]);
	return 0;
}