#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n,k;
int a[N],q[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++ ) scanf("%d",&a[i]);
	
	//单调减队列，求某滑动区间的最小值 
	int hh = 0,tt = -1; ///队列中存储的是下标 
	for(int i = 0; i < n; i ++ ){
		if(hh <= tt && i - k + 1 > q[hh]) hh ++; //判断队头是否出栈
		while(hh <= tt && a[q[tt]] >= a[i])  tt --;
		q[++ tt] = i;
		if(i > k - 1) printf("%d",a[q[hh]]); //队列中（窗口中）第一个数永远是最小的
	} 
	
	return 0;
	
}
