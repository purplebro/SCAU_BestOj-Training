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
typedef pair<double, double> pdd;
const int N = 1e3 + 10;
const int M = 2e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 16711680;
const double eps = 1e-5;

double x[N];
double y[N];
vector<int> G[N];
bool vis[N];

bool dfs(int u) {
    vis[u] = true;
    if (!u)
        return true;
    for (int v : G[u]) if (!vis[v]) {
        if (dfs(v))
            return true;
    }
    return false;
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    int T;

    scanf("%d", &T);

    for (;T--;) {
        int n;
        double r;

        scanf("%d%lf", &n, &r);

        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i], &y[i]);

        double d = 2 * r, d2 = d * d;

        if (d >= 100) {
            puts("No");
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (x[i] <= d) {
                G[0].emplace_back(i);
                G[i].emplace_back(0);
            }
            if (100 - x[i] <= d) {
                G[n + 1].emplace_back(i);
                G[i].emplace_back(n + 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                double f = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if (f - d2 <= eps) {
                    G[i].emplace_back(j);
                    G[j].emplace_back(i);
                }
            }
        }

        if (dfs(n + 1))
            puts("No");
        else
            puts("Yes");

        for (int i = 0; i <= n + 1; i++) {
            G[i].clear();
            vis[i] = false;
        }
    }

    return 0;
}
