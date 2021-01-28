#include <iostream>

int main() {
	size_t n, cnt = 0; 
	if(!scanf("%zu", &n)) return 0;

	double num, total = 0; char str[101], cmp[101];
	for(size_t i = 0; i < n && scanf("%s", str); ++i) {
		bool flag = true;
		sscanf(str, "%lf", &num); sprintf(cmp, "%.2f", num);
		for(size_t j = 0; str[j] != '\0' && flag; ++j) flag = str[j] == cmp[j];
		if(flag && -1000 <= num && num <= 1000) total += num, ++cnt;
		else printf("ERROR: %s is not a legal number\n", str);
	}
	if(cnt == 0) printf("The average of 0 numbers is Undefined\n");
	else printf("The average of %zu %s is %.2lf\n", cnt, cnt == 1 ? "number" : "numbers", total / cnt);
	return 0;
}