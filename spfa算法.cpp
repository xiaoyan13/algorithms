#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;

int d[N];
bool st[N]; //是否在队列中 

void add(int a, int b, int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
} 

void init() {
	memset(h, -1, sizeof h);
	memset(d, 0x3f, sizeof d);
	idx = 0;
}

int spfa() {
	d[1] = 0;
	
	queue<int> q;
	q.push(1);
	st[1] = true;
	
	while (q.size()) {
		int t = q.front();
		q.pop();
		
		st[t] = false;
		
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (d[j] > d[t] + w[i]) {
				d[j] = d[t] + w[i];
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
	if (d[n] > 0x3f3f3f3f / 2) return d[n];
	else return -1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	return 0;
}

/*
spfa是bellman-ford的队列优化，考虑到了n次迭代中每次迭代只有被更新过的点会被用到：
被更新指的是： 1 ： 无穷->常数 2：常数->更小的常数
可以发现只有这两种点会被用到。
用一个队列去维护被更新过的点，不断用这个队列中的点去更新其他点，直到队列为空。
由于这种方式略去了迭代n次的概念，所以判负环就不能像bellman-ford那样，迭代n次后再迭代一次判断有没有更新。
spfa维护一个数组，存储每个点到根节点经过的边数。如果边数大于等于n，就一定存在负环。 
*/ 
