#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> const &tree, vector<int> &path, const size_t &node, bool &isMin, bool &isMax) {
	path.emplace_back(tree[node]);
	if(2 * node + 1 >= tree.size()) {
		for(size_t i = 0; i < path.size(); ++i) printf("%d%c", path[i], " \n"[i==path.size()-1]);
	}
	else {
		if(2 * node + 2 < tree.size()) {		
			if(isMin && tree[node] > tree[2 * node + 2]) isMin = false;
			if(isMax && tree[node] < tree[2 * node + 2]) isMax = false;
			DFS(tree, path, 2 * node + 2, isMin, isMax);
		}
		if(isMin && tree[node] > tree[2 * node + 1]) isMin = false;
		if(isMax && tree[node] < tree[2 * node + 1]) isMax = false;
		DFS(tree, path, 2 * node + 1, isMin, isMax);
	}
	path.pop_back();
}

int main() {
	size_t n;
	if(!scanf("%zu", &n)) return 0;
	
	bool isMin = true, isMax = true;
	vector<int> keys(n), path;
	for(size_t i = 0; i < n && scanf("%d", &keys[i]); ++i);
	DFS(keys, path, 0, isMin, isMax);
	if(isMin || isMax) printf("%s Heap\n", isMin ? "Min" : "Max");
	else printf("Not Heap\n");
	return 0;
}

