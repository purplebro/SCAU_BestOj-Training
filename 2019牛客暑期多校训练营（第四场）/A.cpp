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
#define debug(a) cout << #a": " << a << endl;
const int maxn = 1000+10;
const int maxm = 10;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;

int f[N];
int g[N];
int pre[N << 1];
int suf[N << 1];
int L[N];
int R[N];
int bfn[N << 1];
int tot;
bool tag[N];
vector<int> G[N];

void dfs1(int u, int fa) {
    L[u] = ++tot;
    for (int v : G[u]) if (v != fa)
        bfn[tot++] = v;
    R[u] = tot;
    for (int v : G[u]) if (v != fa) {
        dfs1(v, u);
        if (f[v] != -1)
            f[u] = max(f[u], f[v] + 1);
    }
}
void dfs2(int u, int fa, int dis) {
    g[u] = dis;
    if (u != 1 && ~g[u])
        f[u] = max(f[u], g[u] + 1);
    int limit = R[u];
    pre[L[u] - 1] = -1;
    for (int i = L[u]; i < limit; i++)
        pre[i] = max(pre[i - 1], f[bfn[i]]);
    limit = L[u];
    suf[R[u]] = -1;
    for (int i = R[u] - 1; i >= limit; i--)
        suf[i] = max(suf[i + 1], f[bfn[i]]);
    limit = R[u];
    for (int i = L[u]; i < limit; i++) {
        int d = max({pre[i - 1], suf[i + 1], g[u]});
        if (~d)
            d++;
        else if (tag[u])
            d = 0;
        dfs2(bfn[i], u, d);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    mst(f, -1);

    for (int i = 1; i <= k; i++) {
        int u;
        cin >> u;
        tag[u] = true;
        f[u] = 0;
    }

    dfs1(1, 0);
    dfs2(1, 0, -1);

    int res = inf;

    for (int i = 1; i <= n; i++)
        res = min(res, f[i]);

    if (k == 0)
        res = 0;

    cout << res << "\n";

    return 0;
}
