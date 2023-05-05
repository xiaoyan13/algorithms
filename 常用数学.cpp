#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 100010;

// �ж�����
int prime(int x) {
	if (x < 2) return 0;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
} 

// �ֽ�������
void devide(int x) {
	for (int i = 2; i <= x / i; i++) {
		int s = 0;
		while (x % i == 0) {
			x /= i;
			s++;
		}
		cout << i << " " << s; // i����s�� 
	}
	if (x) cout << x << " " << 1; //����sqrt(x)���Ǹ���������� 
} 

// __gcd�����Լ����
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}


// ����ɸ��
int primes[N], cnt; // ��primes 
bool st[N]; // ��û�б�ɸ�� 

void line_primes(int n) { // 2 ~ n
	for (int i = 2; i <= n; i++) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n/i; j++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		} 
	}
}


// ������
int qmi(int a, int k , int p) {
	int res = 1;
	while (k) {
		if (k & 1) res = (ll)res * a % p;
		a = (ll)a * a % p;
		k >>= 1;
	}
	return res;
} 

int main() {
	
	line_primes(1000);
	for(int i = 0; i < cnt; i ++ )
	{
		cout << primes[i] << " "; 
	}
	cout << endl;
	
	
	return 0;
} 
