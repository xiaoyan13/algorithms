#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

/*
1. ����mid������߻����ұ��������ж����ĸ�����
2. ������һ������������ȡ����ɵ�
3. ������һ�ļǷ���mid���ұ��������+1 
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
