#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	size_t n, m;
	vector<int> prev;
	if(scanf("%zu%zu", &m, &n) != 2) return 0;

	int a, b, root;
	prev.reserve(n);
	unordered_map<int, size_t> index;
	for(size_t i = 0; i < n && scanf("%d", &a); ++i) index[a] = i;
	for(size_t i = 0; i < n && scanf("%d", &a); ++i) prev.emplace_back(a);

	auto between = [](const size_t &a, const size_t &b, const size_t &c) { return a <= b && b <= c;	};
	for(size_t i = 0, u, v, count; i < m && scanf("%d%d", &a, &b); ++i) {
		if((count = index.count(a) + index.count(b)) == 0) 
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if(count == 1)
			printf("ERROR: %d is not found.\n", index.count(a) ? b : a);
		else {
			u = index[a], v = index[b];
			if(u > v) swap(u, v);
			for(const int &node : prev) if(between(u, index[root = node], v)) break;
			if(root == a || root == b)
				printf("%d is an ancestor of %d.\n", root, root == a ? b : a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, root);
		}
	}
	return 0;
}
