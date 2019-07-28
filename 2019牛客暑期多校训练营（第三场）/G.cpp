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
const int N = 3e5 + 10;
const int M = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9 + 7;

int a[N];

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (;T--;) {
        int n;

        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        LL res = 0;

        for (int i = 1; i <= n; i++) {
            int l = i, r = i;
            LL sum = 0;
            for (; l - 1 && sum + a[l - 1] < a[i];) {
                --l;
                sum += a[l];
            }
            for (; r + 1 <= n && sum + a[r + 1] < a[i];) {
                ++r;
                sum += a[r];
            }
            res += r - i + 1;
            for (int j = l; j < i; j++) {
                sum -= a[j];
                for (;r + 1 <= n && sum + a[r + 1] < a[i];) {
                    ++r;
                    sum += a[r];
                }
                res += r - i + 1;
            }
        }

        cout << 1LL * n * (n + 1) / 2 - res << "\n";
    }

    return 0;
}
