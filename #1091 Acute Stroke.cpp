#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef vector<bool> Line;
typedef vector<Line> Slice;
typedef tuple<ssize_t, ssize_t, ssize_t> Position, Pos;

unsigned BFS(const vector<Slice> &isStroke, vector<Slice> &visit, const Pos &pos, ssize_t l, ssize_t m, ssize_t n) {
    unsigned cnt = 1; ssize_t x, y, z;
    auto in = [](const ssize_t &a, const ssize_t &lo, const ssize_t &hi) { return lo <= a && a < hi; };

    array<Pos, 6> offsets{ Pos{-1, 0, 0}, Pos{1, 0, 0}, Pos{0, -1, 0}, Pos{0, 1, 0}, Pos{0, 0, -1}, Pos{0, 0, 1} };
    queue<Pos> q; visit[get<0>(pos)][get<1>(pos)][get<2>(pos)] = true;
    for(q.push(pos); !q.empty(); q.pop()) {
        for(const Pos &offset : offsets) {
            const Pos &f = q.front();
            x = get<0>(f) + get<0>(offset); y = get<1>(f) + get<1>(offset); z = get<2>(f) + get<2>(offset);
            if(!in(x, 0, l) || !in(y, 0, m) || !in(z, 0, n) || !isStroke[x][y][z] || visit[x][y][z]) continue;
            ++cnt; visit[x][y][z] = true; q.emplace(x, y, z);
        }
    }
    return cnt;
}

int main() {
    ssize_t m, n, l, t;
    if(scanf("%zd%zd%zd%zd", &m, &n, &l, &t) != 4) return 0;
    
    vector<Slice> isStroke(l, Slice(m, Line(n))), visit(l, Slice(m, Line(n, false)));
    for(ssize_t i = 0; i < l; ++i) {
        for(ssize_t j = 0; j < m; ++j) {
            for(ssize_t k = 0, flag; k < n && scanf("%zu", &flag); ++k) isStroke[i][j][k] = flag == 1;
        }
    }
    
    unsigned cnt, total = 0;
    for(ssize_t i = 0; i < l; ++i) {
        for(ssize_t j = 0; j < m; ++j) {
            for(ssize_t k = 0; k < n; ++k) {
                if(!isStroke[i][j][k] || visit[i][j][k]) continue;
                if((cnt = BFS(isStroke, visit, Pos{i, j, k}, l, m, n)) >= t) total += cnt;
            }
        }
    }
    printf("%u\n", total);
    return 0;
}