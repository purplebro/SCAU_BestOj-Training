#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 20+10;
const int N = 30 + 10;
const int M = (1 << 14) + 10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9+7;
const double PI = acos(-1.);

int G[N][N];
pii a[M];
pii b[M];
LL dp1[M];
LL dp2[M];
LL to0[20][M];
LL to1[20][M];
int L[20];
int R[20];

int getOne(int x) {
    int res = 0;
    for (; x; x -= lowbit(x))
        res++;
    return res;
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n << 1; i++) {
        for (int j = 0; j < n << 1; j++)
            cin >> G[i][j];
    }

    LL sum = 0;

    for (int i = 0; i < n << 1; i++) {
        for (int j = i + 1; j < n << 1; j++)
            sum += G[i][j];
    }

    int S1 = n;
    int S2 = n;

    for (int i = 0; i < 1 << S1; i++) {
        b[i] = a[i] = pii(getOne(i), i);
        for (int j = 0; j < S1; j++) if (i >> j & 1) {
            for (int k = j + 1; k < S1; k++) if (i >> k & 1)
                dp1[i] += G[j][k];
        }
        for (int j = 0; j < S1; j++) if (!(i >> j & 1)) {
            for (int k = j + 1; k < S1; k++) if (!(i >> k & 1))
                dp1[i] += G[j][k];
        }
        for (int j = 0; j < S2; j++) if (i >> j & 1) {
            for (int k = j + 1; k < S2; k++) if (i >> k & 1)
                dp2[i] += G[j + n][k + n];
        }
        for (int j = 0; j < S2; j++) if (!(i >> j & 1)) {
            for (int k = j + 1; k < S2; k++) if (!(i >> k & 1))
                dp2[i] += G[j + n][k + n];
        }
    }

    for (int i = 0; i < S1; i++) {
        for (int j = 0; j < 1 << S2; j++) {
            for (int k = 0; k < S2; k++) {
                if (j >> k & 1)
                    to1[i][j] += G[i][k + n];
                else
                    to0[i][j] += G[i][k + n];
            }
        }
    }

    sort(a, a + (1 << S1), [](pii a, pii b) {
            return a.X < b.X;
        });
    sort(b, b + (1 << S2), [](pii a, pii b) {
            return a.X > b.X;
         });

    int cnt = 0;

    for (int i = 0; i < 1 << S2; i++) {
        if (b[i].X != b[i + 1].X) {
            R[b[i].X] = i;
            L[b[i].X] = i - cnt;
            cnt = 0;
        } else
            cnt++;
    }

    LL res = 0;

    for (int i = 0; i < 1 << S1; i++) {
        int has = a[i].X;
        int sta1 = a[i].Y;
        int limit = R[n - has];
        for (int j = L[n - has]; j <= limit; j++) {
            int sta2 = b[j].Y;
            LL now = 0;
            for (int k = 0; k < S1; k++) if (sta1 >> k & 1)
                now += to1[k][sta2];
            for (int k = 0; k < S1; k++) if (!(sta1 >> k & 1))
                now += to0[k][sta2];
            res = max(res, sum - now - dp1[sta1] - dp2[sta2]);
        }
    }

    cout << res << "\n";

    return 0;
}
