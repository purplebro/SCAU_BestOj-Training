#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 1000+10;
const int maxm = 10;
const int N = 1000 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;

int head[N];
int nxt[N << 1];
int to[N << 1];
int wt[N << 1];
int dis[N][N];
int tot;
int n, m, S, T, k;
struct Node {
    int u, dist, d;
    bool operator < (const Node &t) const {
        return dist > t.dist;
    }
};
priority_queue<Node> Q;

inline void addEdge(int u, int v, int w) {
    to[++tot] = v;
    nxt[tot] = head[u];
    wt[tot] = w;
    head[u] = tot;
}
void dij(int S) {
    mst(dis, 0x3f);
    dis[0][S] = 0;
    Q.push({S, 0, 0});
    for (;!Q.empty();) {
        Node t = Q.top();
        Q.pop();
        if (dis[t.d][t.u] < t.dist)
            continue;
        int u = t.u;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            int w = wt[i];
            if (dis[t.d][v] > dis[t.d][u] + w) {
                dis[t.d][v] = dis[t.d][u] + w;
                Q.push({v, dis[t.d][v], t.d});
            }
            if (t.d + 1 <= k && dis[t.d + 1][v] > dis[t.d][u]) {
                dis[t.d + 1][v] = dis[t.d][u];
                Q.push({v, dis[t.d + 1][v], t.d + 1});
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> S >> T >> k;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    dij(S);

    int res = inf;

    for (int i = 0; i <= k; i++)
        res = min(res, dis[i][T]);

    cout << res << "\n";

    return 0;
}
