#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int N = 1e5 + 10;

int n, m;
int h[N], e[N], ne[N], w[N], idx;

int d[N];
bool st[N]; //�Ƿ��ڶ����� 

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
spfa��bellman-ford�Ķ����Ż������ǵ���n�ε�����ÿ�ε���ֻ�б����¹��ĵ�ᱻ�õ���
������ָ���ǣ� 1 �� ����->���� 2������->��С�ĳ���
���Է���ֻ�������ֵ�ᱻ�õ���
��һ������ȥά�������¹��ĵ㣬��������������еĵ�ȥ���������㣬ֱ������Ϊ�ա�
�������ַ�ʽ��ȥ�˵���n�εĸ�������и����Ͳ�����bellman-ford����������n�κ��ٵ���һ���ж���û�и��¡�
spfaά��һ�����飬�洢ÿ���㵽���ڵ㾭���ı���������������ڵ���n����һ�����ڸ����� 
*/ 
