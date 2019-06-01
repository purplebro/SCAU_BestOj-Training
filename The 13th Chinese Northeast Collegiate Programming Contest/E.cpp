#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define ls rt<<1
#define rs rt<<1|1
#define lb(x) (x&-x)
#define ALL(x) begin(), end()
const int maxn = 1e5+10;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int head[N];
int cnt;
int to[N << 1];
int nxt[N << 1];
int wt[N << 1];
LL ans;

inline void addEdge(int u, int v, int w) {
    to[++cnt] = v;
    nxt[cnt] = head[u];
    wt[cnt] = w;
    head[u] = cnt;
}
void dfs(int u, int fa, int w) {
    int mi = w;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa)
            continue;
        mi = min(mi, wt[i]);
        dfs(v, u, wt[i]);
    }
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];

        ans += mi + wt[i];
    }
    ans -= mi * 2;

}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int T;
    scanf("%d", &T);
    while (T--){
        int n;

        scanf("%d", &n);

        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        ans = 0;
        dfs(1, 0, inf);

        printf("%lld\n", ans);

        for (int i = 1; i <= n; i++)
            head[i] = 0;
        cnt = 0;
    }
    return 0;
}
