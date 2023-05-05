#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

struct edge {
	int a, b, w;
}g[M];

int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist); //备份 
		for (int j = 0; j < m; j++) {
			int a = g[j].a, b = g[j].b, w = g[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}
	if (dist[n] > 0x3f3f3f3f/2) return -1;
	return dist[n];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m >> k; 
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[i] = {a, b, w};
	}
	
	int t = bellman_ford();
	if (t == -1) puts("impossible");
	else cout << t << "\n";

	return 0;
}

/*
Bellman-Ford和spfa用于处理存在负边的最短路。
如果存在负回路，则到某个点的最短路可能不存在。（也可能存在，只要该点对应的路径中没有负回路就行）
它可以用来判负环：如果第n次迭代让最短路更新了，则图中一定有负环。
求负环一般用spfa，它是堆优化版的bellmanford，时间复杂度期望更低。
v
Bellman-Ford的存边方式不需要去用邻接表，只需要能遍历所有的边就可以 
第k次迭代得到由根节点出发的某一条不超过k条边的最短路径
可以发现每次迭代都会遍历所有的边，总共n次，所以时间复杂度是nm
 
应用场景：大部分情况下spfa都优于bellmanford，除非考虑一些细节，比如有边数限制的最短路 
*/ 

/*
3 3 1
1 2 1
2 3 1
1 3 3
output:
3
*/
