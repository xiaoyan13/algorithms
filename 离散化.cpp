#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e3 + 10;

// ��������ɢ�������ǰ�һ�Ѻ�ɢ����ӳ�䵽����ܼ���1~n��������һһ��Ӧ��˫�䣩�����ұ�֤ÿ��������Դ�С˳�� 

// ��һ�֣���Ҫȥ��
// ����û�м�¼�±�仯������Ѱ���±���ö���
void example() {
	int nums[N], res[N], ans[N]; //nums��ԭ����  res��ԭ��������+ȥ�غ�Ľ��  ans����ɢ�����ֵ 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		res[i] = nums[i];
	}
	
	sort(res + 1, res + 1 + n);
	int cnt = unique(res + 1, res + n + 1) - res - 1; //ȥ�غ�ĳ���
	
	for (int i = 1; i <= n; i++) {
		ans[i] = lower_bound(res + 1, res + cnt + 1, nums[i]) - res; //Ѱ���±���ö��֣����numsû���˿��Ի���nums 
	}
} 

// �ڶ��֣��ṹ������
// ��ɢ�������Ͼ����ڶ�һ����sort��ʱ��ͬʱ��¼ÿ�������±�仯
//ԭ�������ֵ�λ��=ԭ���±������ֵ�λ��=ԭ������������ԭ���±���±������ֵ�λ�ý���˫���ӳ���ϵ��
//���ҵ�ʱ�����ԭ���±�������ԭ�� 

struct Node {
	int data, id;
	bool operator<(const Node& a) const {
		return data < a.data;
	}
}; 

void example1() {
	Node nums[N];
	int rank[N];
	int n; cin>> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i].data;
		nums[i].id = i;
	} 
	sort(nums + 1, nums + 1 + n);
	for (int i = 1; i <= n; i++) {
		rank[nums[i].id] = i; //rank[j] = i��ʾԭ�±�Ϊj��������Դ�С����Ϊi 
	}
}

// �����֣�˫���� ����������ݷŽṹ��� 
int a[N], b[N], c[N]; //a��ԭ���� b��ԭ�����±� c����ɢ����Ľ�� 

bool cmp(int x, int y) {
	if (a[x] == a[y]) return x < y;
	return a[x] < a[y];
}

void example2() {
	// ����Ҫ�ṹ���д�� �����ϻ��Ƕ�ԭ������ֻ�������±�仯ԭ�������� 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = i; //��ʼ�±� 
	}
	
	sort(b + 1, b + n + 1, cmp); //ԭ���±�������� 
	
	for (int i = 1; i <= n; i++) {
		c[b[i]] = i; // �����ɢ��ǰ��������ɢ�����ò����˵Ļ�������д��a[b[i]] = i 
	}
	
	for (int i = 1; i <= n; i++) {
		cout << c[i] << " ";
	} 
}

// �����֣� STL map
// map�ṩ�˳������±�Ľ������map�����ļ��ڵײ㱻��ϣ��ɢ�����±ꡣ�����������ͺ�����Ҫ��ɢ����һ���� 


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	example();
//	example1();
//	example2();
	
	return 0;
}

/*
5
��ʼֵ   5 	500 1 	50 	5000
��ʼ�±� 1 	2 	3	 4	 5

sort����±� 1	 2  	3 	4	 	5 
sort���ֵ 	3(1) 1(5) 4(50) 2(500) 5(5000) 


ΪʲôҪ���±�����ɢ����
�����ϲ���Ҫ����ԭʼ�İ汾��ͨ���������ҵ������ġ����±����ԭ��ֻ��Ϊ�˸�����ķ�����ҵ�ԭ����
*/ 
