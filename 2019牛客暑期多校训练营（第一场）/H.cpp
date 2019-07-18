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
const int N = 62 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

LL base[N];
LL to[N];
int bin[M];
vector<LL> has;

inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    bin[0] = 1;

    for (int i = 1; i < M; i++)
        bin[i] = 2LL * bin[i - 1] % mod;

    int n;

    for (;cin >> n;) {
        mst(base, 0);
        mst(to, 0);
        has.clear();

        for (int i = 1; i <= n; i++) {
            LL a;
            LL p = 0;
            bool flag = true;
            cin >> a;
            for (int j = 60; j >= 0; j--) if (a >> j & 1) {
                if (!base[j]) {
                    base[j] = a;
                    to[j] = p ^ (1LL << j);
                    flag = false;
                    break;
                }
                a ^= base[j];
                p ^= to[j];
            }
            if (flag)
                has.emplace_back(p);
        }

        int res = 1LL * has.size() * bin[has.size() - 1] % mod;

        for (int i = 0; i <= 60; i++) if (base[i]) {
            bool flag = false;
            for (LL it : has) if (it >> i & 1) {
                flag = true;
                break;
            }
            if (flag)
                add(res, bin[has.size() - 1]);
        }

        cout << res << "\n";
    }

    return 0;
}
