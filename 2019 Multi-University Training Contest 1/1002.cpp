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
const int N = 5e5 + 10;
const int M = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9;
const int limit = 29;

int base[31][M];
int id[31][M];

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (;T--;) {
        int n, m;

        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            for (int j = limit; j >= 0; j--) {
                base[j][i] = base[j][i - 1];
                id[j][i] = id[j][i - 1];
            }
            int d = i;
            for (int j = limit; j >= 0; j--) if (a >> j & 1) {
                if (!base[j][i]) {
                    base[j][i] = a;
                    id[j][i] = d;
                    break;
                } else {
                    if (id[j][i] < d) {
                        swap(a, base[j][i]);
                        swap(d, id[j][i]);
                    }
                    a ^= base[j][i];
                }
            }
        }

        int last = 0;

        for (;m--;) {
            int op;
            cin >> op;
            if (!op) {
                int res = 0;
                int l, r;
                cin >> l >> r;
                l = (l ^ last) % n + 1;
                r = (r ^ last) % n + 1;
                if (l > r)
                    swap(l, r);
                for (int i = limit; i >= 0; i--) if (base[i][r] && id[i][r] >= l)
                    res = max(res, res ^ base[i][r]);
                last = res;
                cout << last << "\n";
            } else {
                int x;
                cin >> x;
                x ^= last;
                n++;
                for (int j = limit; j >= 0; j--) {
                    base[j][n] = base[j][n - 1];
                    id[j][n] = id[j][n - 1];
                }
                int d = n;
                for (int j = limit; j >= 0; j--) if (x >> j & 1) {
                    if (!base[j][n]) {
                        base[j][n] = x;
                        id[j][n] = d;
                        break;
                    } else {
                        if (id[j][n] < d) {
                            swap(x, base[j][n]);
                            swap(d, id[j][n]);
                        }
                        x ^= base[j][n];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = limit; j >= 0; j--)
                base[j][i] = id[j][i] = 0;
        }
    }

    return 0;
}
