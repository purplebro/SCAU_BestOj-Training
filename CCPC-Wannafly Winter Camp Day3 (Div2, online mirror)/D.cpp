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
const int N = 14 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-4;

LL dis[N][N];
vector<int> G[M];
bool has[M][N];
LL dp[M][N];

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    mst(dis, -1);
    int n, m;

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        u--;
        v--;
        dis[u][v] = dis[v][u] = w;
    }

    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            G[i].emplace_back(j);
            has[i][j] = true;
        }
    }

    mst(dp, -1);

    for (int i = 1; i < 1 << n; i++) {
        if (G[i].size() == 1)
            dp[i][G[i][0]] = 0;
        else {
            for (int u : G[i]) {
                for (int j = i; j; j = (j - 1) & i) if (!has[j][u] && ~dp[i - j][u]) {
                    int siz = G[j].size();
                    for (int v : G[j]) if (~dis[u][v] && ~dp[j][v])
                        dp[i][u] = max(dp[i][u], dp[j][v] + dp[i - j][u] + dis[u][v] * (siz) * (n - siz));
                }
            }
        }
    }

    LL res = 0;

    for (int i = 0; i < n; i++)
        res = max(res, dp[(1 << n) - 1][i]);

    printf("%lld\n", res);

    return 0;
}
