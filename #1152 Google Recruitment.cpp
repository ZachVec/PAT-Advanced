#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(const unsigned &number) {
	if(number < 2) return false;
	for(unsigned i = 2, upper = sqrt(number); i <= upper; ++i) 
		if(number % i == 0) return false;
	return true;
}

int main() {
	size_t n, k;
	vector<unsigned> digits;
	if(scanf("%zu%zu", &n, &k) != 2) return 0;

	unsigned number;
	for(size_t i = 0; i < n && scanf("%1u", &number); ++i) digits.emplace_back(number);
	for(size_t i = 0; i + k <= n; ++i) {
		number = 0;
		for(size_t j = 0; j < k; ++j) number = number * 10 + digits[i + j];
		if(isPrime(number)) {
			printf("%0*u\n", int(k), number);
			return 0;
		}
	}
	printf("404\n");
	return 0;
}
