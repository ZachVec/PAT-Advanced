#include <iostream>
using namespace std;

int main() {
    size_t n, t1 = (size_t)(-1), t2 = 0;
    string in, out, temp;
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0, t, h, m, s; i < n; ++i) {
        cin >> temp;
        scanf("%zu:%zu:%zu", &h, &m, &s);
        if((t = h * 3600 + m * 60 + s) < t1) {
            t1 = t;
            in = temp;
        }
        scanf("%zu:%zu:%zu", &h, &m, &s);
        if((t = h * 3600 + m * 60 + s) > t2) {
            t2 = t;
            out = temp;
        }
    }
    printf("%s %s\n", in.c_str(), out.c_str());
    return 0;
}

/* input
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40

SC3021234 CS301133
*/