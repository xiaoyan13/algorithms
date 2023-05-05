#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1010; 

int n, m;
int f[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	//重定向cin、cout,提交的时候注掉这两行 
	freopen("input.txt", "r", stdin);
	freopen("dp.txt", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ )
	    {
	        int v, w;
	        cin >> v >> w;
	        for (int j = m; j >= v; j -- )
	            f[j] = max(f[j], f[j - v] + w);
	    } 
	
	cout << f[m] << endl; 
	
	return 0;
}
