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
const int N = 1e5 + 10;
const int M = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

pii operator ^ (const pii &a, const pii &b) {
    return pii(a.X ^ b.X, a.Y ^ b.Y);
}
pii f[500][N];
pii e[N << 1];
pii cur[N];
LL wt[N];
int bl[N << 1];
int blo;
int u[N << 1];
int v[N << 1];
bool tag[500];
int n, m;
mt19937 rnd(time(0));

void update(int L, int R) {
    if (bl[L] == bl[R]) {
        for (int i = L; i <= R; i++) {
            cur[u[i]] = cur[u[i]] ^ e[i];
            cur[v[i]] = cur[v[i]] ^ e[i];
        }
    } else {
        int limit = min(bl[L] * blo, m);
        for (int i = L; i <= limit; i++) {
            cur[u[i]] = cur[u[i]] ^ e[i];
            cur[v[i]] = cur[v[i]] ^ e[i];
        }
        limit = (bl[R] - 1) * blo + 1;
        for (int i = limit; i <= R; i++) {
            cur[u[i]] = cur[u[i]] ^ e[i];
            cur[v[i]] = cur[v[i]] ^ e[i];
        }
        limit = bl[R] - 1;
        for (int i = bl[L] + 1; i <= limit; i++)
            tag[i] ^= 1;
    }
}
void query(int u, int v) {
    pii du = cur[u], dv = cur[v];
    int limit = bl[m];
    for (int i = 1; i <= limit; i++) if (tag[i]) {
        du = du ^ f[i][u];
        dv = dv ^ f[i][v];
    }
    bool flag = true;
    if (du.Y != dv.Y)
        flag = false;
    else {
        if (du.Y) {
            du.X ^= wt[u];
            dv.X ^= wt[v];
        }
        if (du.X != dv.X)
            flag = false;
    }
    cout << flag;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (;T--;) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            wt[i] = rnd();
            cur[i] = pii(0, 0);
        }

        blo = sqrt(m + 0.5);
        blo = max(blo, 2);

        for (int i = 1; i <= m; i++)
            bl[i] = (i - 1) / blo + 1;

        int limit = bl[m];

        for (int i = 1; i <= m; i++) {
            cin >> u[i] >> v[i];
            e[i] = pii(wt[u[i]] ^ wt[v[i]], 1);
        }

        for (int i = 1; i <= limit; i++) {
            tag[i] = true;
            for (int j = 1; j <= n; j++)
                f[i][j] = pii(0, 0);
        }

        for (int i = 1; i <= m; i++) {
            int to = bl[i];
            f[to][u[i]] = f[to][u[i]] ^ e[i];
            f[to][v[i]] = f[to][v[i]] ^ e[i];
        }

        int q;

        cin >> q;

        for (;q--;) {
            int op, u, v;
            cin >> op >> u >> v;
            if (op == 1)
                update(u, v);
            else
                query(u, v);
        }

        cout << "\n";
    }

    return 0;
}
