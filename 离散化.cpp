#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 1e3 + 10;

// 整数的离散化，就是把一堆很散的数映射到相对密集的1~n，让他们一一对应（双射），并且保证每个数的相对大小顺序。 

// 第一种：需要去重
// 由于没有记录下标变化，所以寻找下标采用二分
void example() {
	int nums[N], res[N], ans[N]; //nums：原数组  res：原数组排序+去重后的结果  ans：离散化后的值 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		res[i] = nums[i];
	}
	
	sort(res + 1, res + 1 + n);
	int cnt = unique(res + 1, res + n + 1) - res - 1; //去重后的长度
	
	for (int i = 1; i <= n; i++) {
		ans[i] = lower_bound(res + 1, res + cnt + 1, nums[i]) - res; //寻找下标采用二分；如果nums没用了可以换成nums 
	}
} 

// 第二种：结构体排序
// 离散化本质上就是在对一堆数sort的时候，同时记录每个数的下标变化
//原数最后出现的位置=原数下标最后出现的位置=原数的排名。将原数下标和下标最后出现的位置建立双向的映射关系。
//查找的时候根据原数下标索引到原数 

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
		rank[nums[i].id] = i; //rank[j] = i表示原下标为j的数的相对大小排名为i 
	}
}

// 第三种：双数组 （不想把数据放结构体里） 
int a[N], b[N], c[N]; //a：原数组 b：原数组下标 c：离散化后的结果 

bool cmp(int x, int y) {
	if (a[x] == a[y]) return x < y;
	return a[x] < a[y];
}

void example2() {
	// 不需要结构体的写法 本质上还是对原数排序，只不过是下标变化原数不动了 
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = i; //初始下标 
	}
	
	sort(b + 1, b + n + 1, cmp); //原数下标进行排序 
	
	for (int i = 1; i <= n; i++) {
		c[b[i]] = i; // 如果离散化前的数在离散化后用不到了的话，可以写成a[b[i]] = i 
	}
	
	for (int i = 1; i <= n; i++) {
		cout << c[i] << " ";
	} 
}

// 第四种： STL map
// map提供了超大数下标的解决方案map。它的键在底层被哈希离散化成下标。所以用起来就好像不需要离散化了一样。 


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
初始值   5 	500 1 	50 	5000
初始下标 1 	2 	3	 4	 5

sort后的下标 1	 2  	3 	4	 	5 
sort后的值 	3(1) 1(5) 4(50) 2(500) 5(5000) 


为什么要用下标做离散化？
本质上不需要，最原始的版本是通过二分来找到索引的。用下标代替原数只是为了更快更改方便的找到原数。
*/ 
