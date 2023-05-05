//单调增栈，取出序列某个数左边最近的比该数小的数，没有则为-1 
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int main() {
	int n;
	cin >> n;
	int stk[N],tt = 0;//栈与下标
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (tt && stk[tt] >= x) tt --;
		if (tt) cout << stk[tt] << ' ';
		else cout << 0 << ' ';

		stk[++tt] = x;
	}
}
