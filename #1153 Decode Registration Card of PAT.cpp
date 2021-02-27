#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
using namespace std;
struct Testee{
	tuple<size_t, size_t, size_t> cardNumber;
	unsigned score;
	Testee() = default;
	Testee(size_t const &_site, size_t const &_date, size_t const &_id, unsigned const &_score) : cardNumber(_site, _date, _id), score(_score){}
};

int main() {
	size_t n, q;
	if(scanf("%zu%zu\n", &n, &q) != 2) return 0;		
	
	char level;
	unsigned score;
	vector<Testee> testees;
	unordered_map<char, vector<size_t>> type1;
	unordered_map<size_t, pair<size_t, unsigned>> type2;
	unordered_map<size_t, unordered_map<size_t, size_t>> type3;
	for(size_t i = 0, site, date, id; i < n && scanf("%c%03zu%06zu%03zu %u\n", &level, &site, &date, &id, &score); ++i) {
		testees.emplace_back(site, date, id, score);
		type1[level].emplace_back(i);
		auto &data = type2[site];
		++data.first; data.second += score;
		++type3[date][site];
	}
	
	for(size_t i = 1, type, term; i <= q && scanf("%zu ", &type); ++i) {
		if(type == 1) {
			printf("Case %zu: %zu %c\n", i, type, level = getchar());
			auto &vec = type1[level];
			sort(vec.begin(), vec.end(), [&testees](size_t const &a, size_t const &b){
				return testees[a].score != testees[b].score ? testees[a].score > testees[b].score : testees[a].cardNumber < testees[b].cardNumber;
			});
            for(size_t const &idx : vec) {
                Testee const &testee = testees[idx];
                printf("%c%03zu%06zu%03zu %u\n", level, get<0>(testee.cardNumber), get<1>(testee.cardNumber), get<2>(testee.cardNumber), testee.score);
            }
            if(vec.empty()) printf("NA\n");
        }
		else if(type == 2) {
			if(!scanf("%zu", &term)) continue;
			printf("Case %zu: %zu %03zu\n", i, type, term);
			auto it = type2.find(term);
			if(it == type2.end()) printf("NA\n");
			else printf("%zu %u\n", it->second.first, it->second.second);
		}
		else {
			if(!scanf("%zu", &term)) continue;
			printf("Case %zu: %zu %06zu\n", i, type, term);
			auto it = type3.find(term);
			if(it == type3.end()) printf("NA\n");
			else {
				vector<pair<size_t, size_t>> data;
				for(auto const &kv : it->second) data.emplace_back(kv.first, kv.second);
				sort(data.begin(), data.end(), [](pair<size_t, size_t> const &a, pair<size_t, size_t> const &b){
					return a.second != b.second ? a.second > b.second : a.first < b.first;
				});
				for(auto const &kv : data) printf("%zu %zu\n", kv.first, kv.second);
			}
		}
	}	
	return 0;
}

