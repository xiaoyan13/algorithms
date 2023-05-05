#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int N = 2100, M = 2e5 + 10;

int h[N], e[M], ne[M], idx;
int w[M]; // 存边的信息
bool st[N]; // 有没有确定最短路 
int d[N]; // 答案, d[i] 点i距离源点的最短距离 
int n, m; 

void init() {
    memset(d, 0x3f, sizeof d);
    memset(h, -1, sizeof h);
    idx = 0;
}

void add(int a, int b, int c) { //a指向b 边权为c 
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
	h[a] = idx++;
}

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > hp;
    
    for (int i = 1; i <= n; i++) 
        if (1) { //存入初始确定最短路的点 
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
## 关于dijkstra算法的几个细节

- 提前定义pii，和引入queue头文件。因为后面用到了堆，而且用pair来存的
- init函数中多写了一个初始化d（距离）数组为正无穷。
- dijkstra算法中，集合里的点对应的d已经是最小的了，所以可以直接用d，而不用写什么`int nowdis = t.first`来取距离了。。
- tle了而且过了很多样例八成是数据量很大，记得关流。

bfs的意思是“每轮搜周围相连的点”。
dijk是特殊的bfs，图的边权都是非负数，所以搜相连的点的时候挖掘到了松弛操作的性质，所以可以求最短路。
而迷宫bfs则是一类特殊的dijk，它的边权都是1，所以相比于dijkstra，不需要用优先队列，而是队列就可以，队列里的点的距离本身就依次递增。

dijk的st用于判断有没有确定最短路。 
bellman-ford队列优化得到spfa，用于处理存在负边的图。他们的st数组用于判断点有没有在队列中。 
*/
