#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int N = 2100, M = 2e5 + 10;

int h[N], e[M], ne[M], idx;
int w[M]; // ��ߵ���Ϣ
bool st[N]; // ��û��ȷ�����· 
int d[N]; // ��, d[i] ��i����Դ�����̾��� 
int n, m; 

void init() {
    memset(d, 0x3f, sizeof d);
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) { //aָ��b ��ȨΪc 
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > hp;
    
    for (int i = 1; i <= n; i++) 
        if (1) { //�����ʼȷ�����·�ĵ� 
            hp.push({0, i});
            d[i] = 0;
        }
        
    while (hp.size()) {
        auto item = hp.top();
        hp.pop();
        
        int t = item.second;
        if (st[t]) continue;
        st[t] = true;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                 hp.push({d[j], j});
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    init();
    
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    
    dijkstra();
    
    cout << d[n] << "\n";
    
    return 0;
}

/*
## ����dijkstra�㷨�ļ���ϸ��

- ��ǰ����pii��������queueͷ�ļ�����Ϊ�����õ��˶ѣ�������pair�����
- init�����ж�д��һ����ʼ��d�����룩����Ϊ�����
- dijkstra�㷨�У�������ĵ��Ӧ��d�Ѿ�����С���ˣ����Կ���ֱ����d��������дʲô`int nowdis = t.first`��ȡ�����ˡ���
- tle�˶��ҹ��˺ܶ������˳����������ܴ󣬼ǵù�����

bfs����˼�ǡ�ÿ������Χ�����ĵ㡱��
dijk�������bfs��ͼ�ı�Ȩ���ǷǸ����������������ĵ��ʱ���ھ����ɳڲ��������ʣ����Կ��������·��
���Թ�bfs����һ�������dijk�����ı�Ȩ����1�����������dijkstra������Ҫ�����ȶ��У����Ƕ��оͿ��ԣ�������ĵ�ľ��뱾������ε�����

dijk��st�����ж���û��ȷ�����·�� 
bellman-ford�����Ż��õ�spfa�����ڴ�����ڸ��ߵ�ͼ�����ǵ�st���������жϵ���û���ڶ����С� 
*/
