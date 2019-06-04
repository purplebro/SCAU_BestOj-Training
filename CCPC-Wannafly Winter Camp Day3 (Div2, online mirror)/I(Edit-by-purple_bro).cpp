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
const int N = 2e5 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-4;

int n, m;
int fa[N];
int f[N];
int w[N];
int rnk[N];
struct Node {
    int fa, f, w;
};

Node getFa(int u) {
    int tmp = u;
    int df = 0, dw = 0;
    for (; tmp != fa[tmp];) {
        df += f[tmp];
        dw += w[tmp];
        tmp = fa[tmp];
    }
    df += f[tmp];
    dw += w[tmp];
    return {tmp, df, dw};
}
void mer(int u, int v) {
    Node du = getFa(u), dv = getFa(v);
    if (du.fa != dv.fa) {
        f[dv.fa]++;
        f[du.fa]++;
        w[du.fa]++;
        if (rnk[du.fa] >= rnk[dv.fa]) {
            rnk[du.fa]++;
            fa[dv.fa] = du.fa;
            f[dv.fa] -= f[du.fa];
            w[dv.fa] -= w[du.fa];
        } else {
            rnk[dv.fa]++;
            fa[du.fa] = dv.fa;
            f[du.fa] -= f[dv.fa];
            w[du.fa] -= w[dv.fa];
        }
    }
}
inline int q_pow(int base, int b) {
    int res = 1;
    for (; b; b >>= 1, base = 1LL * base * base % mod) if (b & 1)
        res = 1LL * res * base % mod;
    return res;
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    int b = q_pow(3, n);
    int inv3 = q_pow(3, mod - 2);

    for (;m--;) {
        int op, u, v;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d", &u, &v);
            mer(u, v);
        } else {
            scanf("%d", &u);
            Node t = getFa(u);
            printf("%d\n", 1LL * q_pow(2, t.w) * b % mod * q_pow(inv3, t.w) % mod * q_pow(inv3, t.f - t.w) % mod);
        }
    }

    return 0;
}
