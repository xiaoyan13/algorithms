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
		memcpy(backup, dist, sizeof dist); //���� 
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
Bellman-Ford��spfa���ڴ�����ڸ��ߵ����·��
������ڸ���·����ĳ��������·���ܲ����ڡ���Ҳ���ܴ��ڣ�ֻҪ�õ��Ӧ��·����û�и���·���У�
�����������и����������n�ε��������·�����ˣ���ͼ��һ���и�����
�󸺻�һ����spfa�����Ƕ��Ż����bellmanford��ʱ�临�Ӷ��������͡�
v
Bellman-Ford�Ĵ�߷�ʽ����Ҫȥ���ڽӱ�ֻ��Ҫ�ܱ������еı߾Ϳ��� 
��k�ε����õ��ɸ��ڵ������ĳһ��������k���ߵ����·��
���Է���ÿ�ε�������������еıߣ��ܹ�n�Σ�����ʱ�临�Ӷ���nm
 
Ӧ�ó������󲿷������spfa������bellmanford�����ǿ���һЩϸ�ڣ������б������Ƶ����· 
*/ 

/*
3 3 1
1 2 1
2 3 1
1 3 3
output:
3
*/
