//������ջ��ȡ������ĳ�����������ıȸ���С������û����Ϊ-1 
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int main() {
	int n;
	cin >> n;
	int stk[N],tt = 0;//ջ���±�
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (tt && stk[tt] >= x) tt --;
		if (tt) cout << stk[tt] << ' ';
		else cout << 0 << ' ';

		stk[++tt] = x;
	}
}
