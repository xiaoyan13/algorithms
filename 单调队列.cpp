#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n,k;
int a[N],q[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i ++ ) scanf("%d",&a[i]);
	
	//���������У���ĳ�����������Сֵ 
	int hh = 0,tt = -1; ///�����д洢�����±� 
	for(int i = 0; i < n; i ++ ){
		if(hh <= tt && i - k + 1 > q[hh]) hh ++; //�ж϶�ͷ�Ƿ��ջ
		while(hh <= tt && a[q[tt]] >= a[i])  tt --;
		q[++ tt] = i;
		if(i > k - 1) printf("%d",a[q[hh]]); //�����У������У���һ������Զ����С��
	} 
	
	return 0;
	
}
