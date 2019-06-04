#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
typedef pair<int, int> pii;
const int N = 1e5 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-4;

int n, q;
vector<int> G[N];
bool g[N];
bool f[N];
bool pre[N << 1];
bool suf[N << 1];
int L[N];
int R[N];
int bfn[N << 1];
int tot;

void dfs1(int u, int fa) {
    L[u] = ++tot;
    for (int v : G[u]) if (v != fa)
        bfn[++tot] = v;
    R[u] = tot;
    for (int v : G[u]) if (v != fa) {
        dfs1(v, u);
        g[u] |= g[v];
    }
    g[u] = g[u] ^ 1;
}
void dfs2(int u, int fa, bool p) {
    f[u] = p ^ 1;
    for (int i = L[u] + 1; i <= R[u]; i++)
        pre[i] = pre[i - 1] | g[bfn[i]];
    for (int i = R[u]; i > L[u]; i--)
        suf[i] = suf[i + 1] | g[bfn[i]];
    for (int i = L[u] + 1; i <= R[u]; i++) {
        int v = bfn[i];
        dfs2(v, u, pre[i - 1] | f[u] | suf[i + 1]);
    }
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d", &n, &q);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0, true);

    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans += g[i];

    int t = ans;

    printf("%d\n", ans);

    bool now = g[1];

    for (;q--;) {
        int u;
        scanf("%d", &u);
        if (now) {
            ans = 1LL * ans * n % mod;
            now = false;
        } else {
            ans = (1LL * ans * n % mod + t) % mod;
            now = g[u] & !f[u];
        }
        printf("%d\n", ans);
    }

    return 0;
}
