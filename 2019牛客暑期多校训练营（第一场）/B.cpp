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
typedef unsigned long long ULL;
typedef double db;
typedef pair<int, int> pii;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

int a[N];

inline int q_pow(int base, int b) {
    int res = 1;
    for (; b; b >>= 1, base = 1LL * base * base % mod) if (b & 1)
        res = 1LL * base * res % mod;
    return res;
}
inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
inline int sqr(int x) {
    return 1LL * x * x % mod;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    for (;cin >> n;) {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        int res = 0;

        for (int i = 1; i <= n; i++) {
            int tmp = 1;
            for (int j = 1; j <= n; j++) if (i != j)
                tmp = 1LL * tmp * (sqr(a[j]) - sqr(a[i]) + mod) % mod;
            tmp = q_pow(tmp, mod - 2);
            add(res, 1LL * tmp * q_pow(2 * a[i], mod - 2) % mod);
        }

        cout << res << "\n";
    }

    return 0;
}
