#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

struct DSU {
    std::vector<int> f, sz;
    DSU(int n) : f(n), sz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return sz[find(x)]; }
};

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
     
    int n, m;
    std::cin >> n >> m;
    
	DSU dsu(n + 1);
	for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        dsu.merge(u, v);
	}

	return 0;
}
