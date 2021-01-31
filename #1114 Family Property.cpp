#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    size_t n;

    if(!scanf("%zu", &n)) return 0;
    vector<size_t> rootOf(10000, -1);
    auto Find = [&rootOf](size_t root) {
        vector<size_t> path;
        for(; root != rootOf[root]; root = rootOf[root]) path.emplace_back(root);
        for(const size_t &node : path) rootOf[node] = root;
        return root;
    };
    auto Union = [&rootOf, &Find](size_t a, size_t b) {
        if(rootOf[a] == size_t(-1)) rootOf[a] = a;
        if(rootOf[b] == size_t(-1)) rootOf[b] = b;
        size_t rootOfa = Find(a), rootOfb = Find(b);
        if(rootOfa == rootOfb) return;
        if(rootOfa > rootOfb) rootOf[rootOfa] = rootOfb;
        else rootOf[rootOfb] = rootOfa;
    };

    typedef pair<unsigned, unsigned> Asset; // #estate, #area
    vector<Asset> assets(10000);
    for(size_t i = 0, id, dad, mom, k; i < n && scanf("%zu%zu%zu%zu", &id, &dad, &mom, &k); ++i) {
        if(rootOf[id] == size_t(-1)) rootOf[id] = id;
        if(dad != size_t(-1)) Union(dad, id);
        if(mom != size_t(-1)) Union(mom, id);
        for(size_t j = 0, child; j < k && scanf("%zu", &child); ++j) Union(child, id);
        if(scanf("%u%u", &assets[id].first, &assets[id].second) != 2) return 0;
    }

    typedef tuple<unsigned, unsigned, unsigned> FamilyAsset; // #Members, #family estates, #family area
    unordered_map<size_t, FamilyAsset> familyAssets;
    for(size_t i = 0; i < rootOf.size(); ++i) {
        if(rootOf[i] == size_t(-1)) continue;
        FamilyAsset &asset  = familyAssets[Find(i)];
        get<0>(asset) += 1; 
        get<1>(asset) += assets[i].first;
        get<2>(asset) += assets[i].second;
    }

    typedef pair<size_t, double> COMP; // id, avgArea
    vector<COMP> ans;
    for(const auto &kv : familyAssets) {
        ans.emplace_back(kv.first, double(get<2>(kv.second)) / double(get<0>(kv.second)));
    }
    sort(ans.begin(), ans.end(), [](const COMP &a, const COMP &b){
        return a.second != b.second ? a.second > b.second : a.first < b.first;
    });
    
    printf("%zu\n", ans.size());
    for(const COMP &comp : ans) {
        const FamilyAsset &asset = familyAssets[comp.first];
        printf("%04zu %u %.3f %.3f\n", comp.first, get<0>(asset), double(get<1>(asset)) / double(get<0>(asset)), comp.second);
    }
    return 0;
}