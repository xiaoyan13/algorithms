#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

/*
1. 根据mid落在左边还是右边区间来判断用哪个板子
2. 补偿加一是整数二分下取整造成的
3. 补偿加一的记法：mid在右边区间就是+1 
*/ 

bool check(int x) {
	return 0;
}

int bsearch_1(int l, int r) {
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	return l;
}

int bsearch_2(int l, int r) {
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) r = mid;
		else r = mid - 1;
	}
	return l;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	
	
	return 0;
}
