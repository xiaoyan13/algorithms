#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1010;

int n, m;
int v[N], w[N];
int ans;

void dfs(int u, int sum, int value)
{
    if (u == n) ans = max(ans, value);
    else
    {
        dfs(u + 1, sum, value);

        if (sum + v[u] <= m)
            dfs(u + 1, sum + v[u], value + w[u]);
    }
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("input.txt", "r", stdin);
	freopen("dfs.txt", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i ++ ) cin >> v[i] >> w[i];
	
    dfs(0, 0, 0);

    cout << ans << endl; 
	
	return 0;
}
