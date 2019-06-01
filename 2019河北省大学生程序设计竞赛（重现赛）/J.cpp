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
const int N = 1e6 + 10;
const int M = 2e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 16711680;
const double eps = 1e-7;

int to[N];
int deg[N];
bool vis[N];
struct Node {
    int u, d;
    bool operator < (const Node &t) const {
        return d > t.d;
    }
};
priority_queue<Node> Q;

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &to[i]);
        deg[to[i]]++;
    }

    for (int i = 1; i <= n; i++)
        Q.push({i, deg[i]});

    int ans = 0;

    for (;!Q.empty();) {
        Node t = Q.top();
        Q.pop();
        int u = t.u;
        if (vis[u] || vis[to[u]])
            continue;
        vis[u] = vis[to[u]] = true;
        deg[to[to[u]]]--;
        ans += 2;
        Q.push({to[to[u]], deg[to[to[u]]]});
    }

    printf("%d\n", n - ans);

    return 0;
}
