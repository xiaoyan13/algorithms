#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e6 + 10;

void create_dataset() {
	ofstream fout("input.txt"); 
	 
	int n = rand() % 20 + 1, m = rand() % 1001; 
	
	fout << n << " " << m << "\n";
	
	for (int i = 0; i < n; i++) {
		int v = rand() % 1001, w = rand() % 1001;
		fout << v << " " << w << "\n";
	} 
	
	fout.close(); // 关流 
} 

// 对拍 
bool work() {
	create_dataset();
	
	system("待提交代码.exe");
	system("暴力代码.exe");
	
	return !system("fc dp.txt dfs.txt"); // 成功为0 所以取非 
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

//	srand(time(0)); // 重新生成随机数的函数 
	
	work();
	
	for (int i = 0; i < 100; i++) { // 一次work成功后进行批量数据测试 
		if (!work()) break;
	}
	return 0;
}

/*
主要就几个函数
ofstream fout
rand srand(time(0))
system("..exe") system("fc a.txt b.txt") 
*/ 
