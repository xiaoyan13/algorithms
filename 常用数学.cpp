#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 100010;

// 判断素数
int prime(int x) {
	if (x < 2) return 0;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) return 0;
	}
	return 1;
} 

// 分解质因数
void devide(int x) {
	for (int i = 2; i <= x / i; i++) {
		int s = 0;
		while (x % i == 0) {
			x /= i;
			s++;
		}
		cout << i << " " << s; // i出现s次 
	}
	if (x) cout << x << " " << 1; //大于sqrt(x)的那个数单独输出 
} 

// __gcd（最大公约数）
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}


// 线性筛法
int primes[N], cnt; // 存primes 
bool st[N]; // 有没有被筛掉 

void line_primes(int n) { // 2 ~ n
	for (int i = 2; i <= n; i++) {
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0; primes[j] <= n/i; j++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		} 
	}
}


// 快速幂
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
