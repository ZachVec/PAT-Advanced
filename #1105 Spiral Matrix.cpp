#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ssize_t n, row, col; 
    if(!scanf("%zu", &n)) return 0;
	for(col = sqrt(n); n % col != 0; --col); 
    row = n / col;

    vector<unsigned> nums(n), ans(n);
	for(unsigned &i : nums) if(!scanf("%u", &i)) return 0;
	sort(nums.begin(), nums.end(), greater<unsigned>());

	for(ssize_t level = 0, now = 0; now < n; ++level) {
		ssize_t iMAX = row - level - 1, jMAX = col - level - 1;
		for(ssize_t i = level,     j = level; now < n && j <= jMAX;  j++) ans[i * col + j] = nums[now++];
		for(ssize_t i = level + 1, j = jMAX;  now < n && i < iMAX;   i++) ans[i * col + j] = nums[now++];
		for(ssize_t i = iMAX,      j = jMAX;  now < n && j >= level; j--) ans[i * col + j] = nums[now++];
		for(ssize_t i = iMAX - 1,  j = level; now < n && i > level;  i--) ans[i * col + j] = nums[now++];
	}
	for(ssize_t i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i % col == col-1]);
	return 0;
}