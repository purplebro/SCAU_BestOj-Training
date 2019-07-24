#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define ALL(x) x.begin(), x.end()
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
typedef double db;
typedef pair<int, int> pii;
const int N = 500 + 10;
const int M = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

struct Edge {
    int v, nxt, f;
}e[M];
int src, sink;
int head[N + 10];
int tot;

inline void addEdge(int u, int v, int c) {
    e[++tot] = {v, head[u], c};
    head[u] = tot;
    e[++tot] = {u, head[v], 0};
    head[v] = tot;
}
void init() {
    mst(head, 0);
    tot = 1;
}
queue<int> Q;
bool vis[N];
int dis[N];
void bfs() {
    mst(dis, 0);
    for (;!Q.empty();)
        Q.pop();
    vis[src] = true;
    Q.push(src);
    for (;!Q.empty();) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {
            if (e[i].f && !vis[e[i].v]) {
                Q.push(e[i].v);
                dis[e[i].v] = dis[u] + 1;
                vis[e[i].v] = true;
            }
        }
    }
}
int dfs(int u, int del) {
    if (u == sink) {
        return del;
    } else {
        int ret = 0;
        for (int i = head[u]; del && i; i = e[i].nxt) {
            if (e[i].f && dis[e[i].v] == dis[u] + 1) {
                int dd = dfs(e[i].v, min(e[i].f, del));
                e[i].f -= dd;
                e[i ^ 1].f += dd;
                del -= dd;
                ret += dd;
            }
        }
        return ret;
    }
}
LL dinic() {
    LL ret = 0;
    for (;;) {
        mst(vis, false);
        bfs();
        if (!vis[sink])
            return ret;
        ret += dfs(src, inf);
    }
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    for (;cin >> n >> m;) {
        LL sum = 0;
        init();
        src = 0;
        sink = n + 1;
        for (int i = 1; i <= m; i++) {
            int u, v, a, b, c;
            cin >> u >> v >> a >> b >> c;
            a <<= 1;
            b <<= 1;
            c <<= 1;
            sum += a + b + c;
            addEdge(src, u, (a + b) / 2);
            addEdge(src, v, (a + b) / 2);
            addEdge(u, sink, (c + b) / 2);
            addEdge(v, sink, (c + b) / 2);
            addEdge(u, v, (a + c) / 2 - b);
            addEdge(v, u, (a + c) / 2 - b);
        }

        cout << (sum - dinic()) / 2 << "\n";
    }

    return 0;
}
