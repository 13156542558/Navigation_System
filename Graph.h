//随机函数,kd树主体,最短路函数等
// #include<bits/stdc++.h>
// #include<bits/extc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <map>
#include <windows.h>
#include <queue>
#include <random>
#include "BasicStruct.h"


// 生成随机数函数，默认生成0到指定范围内的随机数
unsigned long long myRand(unsigned long long range = 0) {
    static std::random_device rd; // 使用随机设备生成种子
    static std::mt19937_64 gen(rd()); // 使用随机种子初始化生成器

    if (range == 0) {
        return gen(); // 返回生成器生成的随机数
    } else {
        std::uniform_int_distribution<unsigned long long> distrib(0, range); // 定义均匀分布
        return distrib(gen); // 生成范围内的随机数
    }
}

namespace Solution{
struct Node {
    Point point;
    Node* left;
    Node* right;
    // Constructor
    Node(Point pt) : point(pt), left(nullptr), right(nullptr) {}

};
Node* root;
Node* buildKDTree(std::vector<Point>& points, int l, int r, int depth) {
    if (l >= r) return nullptr;

    int mid = l + (r - l) / 2;
    auto comparator = [depth](const Point& a, const Point& b) {
        return (depth % 2 == 0) ? (a.x < b.x) : (a.y < b.y);
    };

    std::nth_element(points.begin() + l, points.begin() + mid, points.begin() + r, comparator);

    Node* node = new Node(points[mid]);
    node->left = buildKDTree(points, l, mid, depth + 1);
    node->right = buildKDTree(points, mid + 1, r, depth + 1);

    return node;
}
void KDTree(std::vector<Point>& points) {
    root = buildKDTree(points, 0, points.size(), 0);
}
}

class Graph
{
    bool randFlag;
    unsigned int pointNums;
    HANDLE randFlowThread;
public:
    std::vector<std::vector<std::pair<int, int>>> G; // 这里记录两个数: first记录其目的点标号, second记录该边标号
    std::vector<Point> P; // 点池, 用来存放点的信息, 标号从1开始
    std::vector<Edge> E;  // 边池, 用来存放边的信息, 标号从0开始
    std::vector<int> Res;
    std::vector<int> Gas;
    // 感觉不太需要这个构造函数. 可以设定为构造的时候一定要制定点数.
    // Graph() {}
private:
    int getRoadType() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 10); // 生成范围为 [1, 10] 的随机数

            int randomValue = distrib(gen);

            if (randomValue <= 4) {
                return 1; // 高速公路 (40% 概率)
            } else if (randomValue <= 8) {
                return 2; // 城市道路 (40% 概率)
            } else {
                return 3; // 乡村道路 (20% 概率)
            }
    }
    // 辅助函数, 增加边
    void addEdge(int u, int v) {
            int roadType = getRoadType(); // 获取道路类型
            double _dis = distance(P[u], P[v]);
            int _cap = 0;

            // 根据道路类型设定不同的容量
            switch (roadType) {
            case 1: // 高速公路
                _cap = (int)(myRand(RAND_MAX) * 1.0 / RAND_MAX + 1) * (int)(_dis) / 10 +
                       myRand(50) + 150;
                break;
            case 2: // 城市道路
                _cap = (int)(myRand(RAND_MAX) * 1.0 / RAND_MAX + 1) * (int)(_dis) / 20 +
                       myRand(30) + 80;
                break;
            case 3: // 乡村道路
                _cap = (int)(myRand(RAND_MAX) * 1.0 / RAND_MAX + 1) * (int)(_dis) / 30 +
                       myRand(20) + 50;
                break;
            }

            // 根据时间模拟流量波动
            // ////////////////获取高峰时段

            int _flow = 0;
            // 正常时段
                 int temp= myRand(100);
                if(temp<3)
                {

                    _flow = (int)(_cap *2.0);}
                else
                    _flow = (int)(_cap * 0.8); // 流量降低至 80%



            E.push_back(Edge(u, v, _dis, _cap, _flow));
            G[u].push_back({v, (int)E.size() - 1});
            E.push_back(Edge(v, u, _dis, _cap, _flow));
            G[v].push_back({u, (int)E.size() - 1});
    }
public:
    // 构造一个点数为n的图, 要求尽量合理
    Graph(int __n)
    {
            // 使用随机分布生成点的位置
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> distrib(0.0, 32767.0); // 范围为 0 到 32767

            pointNums = __n;
            int sqn = pow(__n, 0.6);
            srand(time(0));
            G.resize(__n + 1);
            P.resize(__n + 1);

            // 生成随机点坐标
            for (int i = 1; i <= __n; ++i) {
                P[i].x = distrib(gen);
                P[i].y = distrib(gen);
                int fir = myRand(100);
                int sec = myRand(100);
                if (fir % 100 == 1)
                    Res.push_back(i);
                if (sec % 100 == 2)
                    Gas.push_back(i);
            }

            // 利用 KD 树进行预处理
            Solution::KDTree(P);
            int maxDistance = std::max({distance(P[1], P[__n]), distance(P[__n / 2], P[__n]), distance(P[1], P[__n / 2])});
            maxDistance = pow(maxDistance, 0.8);

            // 随机加边，考虑点类型和距离
            for (int i = 2; i <= __n; ++i) {
                std::vector<std::pair<int, int>> __qq;
                int s_t = std::max(1, i - (int)pow(__n, 0.7));
                for (int j = 1; j < i; ++j) {
                    if (__qq.size() < 2) {
                        __qq.push_back({(int)distance(P[i], P[j]), j});
                    } else {
                        int _dis = distance(P[i], P[j]);
                        if (_dis < __qq.front().first && myRand(__n) < sqn) {
                            continue;
                        }
                        std::pair<int, int> now = {_dis, j};
                        for (int k = 0; k < (int)__qq.size(); ++k) {
                            if (__qq[k].first > _dis) {
                                swap(__qq[k], now);
                            }
                        }
                        if (myRand(__n) < sqn) {
                            swap(now, __qq.back());
                        }
                    }
                    if (!__qq.empty() && (myRand(__n) < sqn)) {
                        __qq.pop_back();
                    }
                    if (j < s_t) {
                        j += pow(__n, 0.2);
                    }
                }

                for (auto [_dis, t_o] : __qq) {
                    // 考虑点类型，增加加油站和餐馆之间的连接概率
                    if (std::find(Res.begin(), Res.end(), i) != Res.end() &&
                        std::find(Gas.begin(), Gas.end(), t_o) != Gas.end()) {
                        _dis *= 0.8; // 降低距离影响，提高连接概率
                    }

                    if (_dis > maxDistance && myRand(__n) > sqn) {
                        continue;
                    }
                    addEdge(i, t_o);
                }
            }
    }


    ~Graph() {}

    // 返回输入点附近的100个点的标号
    std::vector<int> getClosestPoints(Point Now_p)
    {
        std::vector<int> ret;
        std::priority_queue<std::pair<double, int> > pq; // 存放100个点的堆.

        for (int i = 1; i <= (int)pointNums; ++i) {
            pq.push({distance(P[i], Now_p), i}); // priority_queue默认大顶堆
            if (pq.size() > 100) pq.pop();
        }

        // 把最近的至多100个点放入ret返回.
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.second);
        }
        return ret;
    }
    // 返回起点附近的5个加油站和餐馆标号
    std::vector<int> GetClosestServicePoints(Point Now_p,std::vector<int>& servicePointlist)
    {
        std::vector<int> ret;
        std::priority_queue<std::pair<double, int> > pq; // 存放5个点的堆.

        for (int i = 0; i < (int)servicePointlist.size(); ++i) {
            pq.push({distance(P[servicePointlist[i]], Now_p), servicePointlist[i]}); // priority_queue默认大顶堆
            if (pq.size() > 5) pq.pop();
        }

        // 把最近的至多5个点放入ret返回.
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.second);
        }
        return ret;
    }

    // 返回邻接链表的头指针
    std::vector<std::vector<std::pair<int, int>>>::iterator graphHead()
    {
        return G.begin();
    }
    // 返回点池的首指针
    std::vector<Point>::iterator pointBegin()
    {
        return P.begin();
    }
    // 返回边池的首指针
    std::vector<Edge>::iterator edgeBegin()
    {
        return E.begin();
    }
    // 返回图中点的数目
    unsigned getPointNums()
    {
        return pointNums;
    }
    // 返回图中边的数目
    unsigned getEdgeNums()
    {
        return (unsigned)E.size();
    }

    DWORD WINAPI static RandFlow(LPVOID lpParameter)
    {
        // 将无类型指针 lpParameter 转换为所需要的 Graph 指针. 然后在图上进行随机修改
        Graph *This = (Graph *)lpParameter;
        while (This->randFlag)
        {
            // 遍历所有的边进行随机修改.
            for (int i = 0; i < (int)This->E.size(); i += 2)
            {
                    // 先进行一个至多 0.76 次方的随机上下浮动
                    This->E[i].flow += ((int)myRand() - (int)myRand()) % ((int)pow(This->E[i].flow, 0.5) + 1);

                    // 处理向下溢出的情况(flow 是 unsigned 的)
                    if (This->E[i].flow > 100000000)
                        This->E[i].flow = std::max(0u, This->E[i].flow + std::min(0u, (unsigned int)sqrt(This->E[i].capacity)));
                    // 处理 flow 超出2倍的 capacity 的情况.
                    if (This->E[i].flow > This->E[i].capacity * 2)
                        This->E[i].flow = std::min(This->E[i].capacity * 2, This->E[i].flow - (int)sqrt(This->E[i].capacity * 2));
                    // 处理无向图的另一条对应的边.
                    This->E[i + 1].flow = This->E[i].flow;
            }
            Sleep(100);
        }

    }
    // 创建一个进程来改变flow
    void startRandFlow()
    {
        randFlag = 1;
        randFlowThread = CreateThread(NULL, 0, RandFlow, this, 0, NULL);
    }

    void stopRandFlow()
    {
        randFlag = 0;
    }

    //实际最短路转换函数

    void Time(std::vector<Edge>::iterator E, Graph *G)
    {

        for (int i = 0; i < (int)G->getEdgeNums(); i += 1)
        {
            if (E[i].flow <= E[i].capacity)
                E[i].realLength = E[i].length / 50;
            else
            {
                double x = (double)E[i].flow / E[i].capacity;
                E[i].realLength = E[i].length / 50 * (1 + exp(x));
            }
        }
    }

    // dij（起点点号，终点点号，图指针）
    // bool类型用来确定计算时间还是距离true表示计算时间即realLength false表示物理距离length，引用参数totallength表示最短路径的通行所需时间或距离根据bool决定）
    //返回最短路路径；
    std::vector<int> dij(int start, int end, Graph *Gp, bool time, double &distance, double &tim)
    {
        tim = 0;
        distance = 0;
        auto E = Gp->edgeBegin();
        std::vector<int> path;
        auto G = Gp->graphHead();
        int n = Gp->getPointNums();
        Time(E, Gp);
        std::vector<double> d(n + 1, 1000000000);
        std::priority_queue<std::pair<double, std::pair<int, int>>> hp;
        hp.push({0, {start, 0}});
        std::vector<int> fa(n + 1);
        std::vector<bool> vis(n + 1);
        while (!hp.empty())
        {
            auto [len, nowe] = hp.top();
            auto [now, fae] = nowe;
            hp.pop();
            if (vis[now])
                continue;
            d[now] = -len;
            fa[now] = fae;
            vis[now] = 1;
            for (auto [to, e] : G[now])
            {
                if (vis[to])
                    continue;
                double ll = 0;
                if (time)
                    ll = len - E[e].realLength;
                else
                    ll = len - E[e].length;
                hp.push({ll, {to, e}});
            }
            if (now == end)
            {
                while (now != start)
                {

                    path.push_back(fa[now]);
                    now = E[fa[now]].P1;
                }

                for (int i = 0; i < (int)path.size(); i++)
                {

                    tim += E[path[i]].realLength;

                    distance += E[path[i]].length;
                }

                return path;
            }
        }

        return path;
    }
};
