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
	
	fout.close(); // ���� 
} 

// ���� 
bool work() {
	create_dataset();
	
	system("���ύ����.exe");
	system("��������.exe");
	
	return !system("fc dp.txt dfs.txt"); // �ɹ�Ϊ0 ����ȡ�� 
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

//	srand(time(0)); // ��������������ĺ��� 
	
	work();
	
	for (int i = 0; i < 100; i++) { // һ��work�ɹ�������������ݲ��� 
		if (!work()) break;
	}
	return 0;
}

/*
��Ҫ�ͼ�������
ofstream fout
rand srand(time(0))
system("..exe") system("fc a.txt b.txt") 
*/ 
