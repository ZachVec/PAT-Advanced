#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
constexpr size_t notExist = -1UL;

int main() {
	size_t n, m, k;
	if(scanf("%zu%zu", &n, &m) != 2) return 0;

	typedef pair<size_t, size_t> Edge;
	vector<Edge> edges;
	for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) edges.emplace_back(u, v);

	if(!scanf("%zu", &k)) return 0;
	vector<size_t> colorOf(n);
	unordered_set<size_t> color;
	for(size_t i = 0; i < k; ++i) {
		bool isColoring = true;
		colorOf.assign(colorOf.size(), notExist); color.clear();
		for(size_t j = 0; j < n && scanf("%zu", &colorOf[j]); ++j) color.insert(colorOf[j]);
		for(Edge const &edge : edges) if(!(isColoring = (colorOf[edge.first] != colorOf[edge.second]))) break;
		if(isColoring) printf("%zu-coloring\n", color.size());
		else printf("No\n");
	}

	return 0;
}

