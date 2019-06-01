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
const int N = 2e5 + 10;
const int maxn = 1e6 + 10;
const int maxm = 2.5e7 + 10;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const ll mod = 1e9+7;
const double eps = 1e-8;


int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T;

    scanf("%d", &T);

    for (;T--;) {
        int n, d;

        scanf("%d%d", &n, &d);

        if (n == 0)
            puts("0");
        else {
            int ans = 1;

            for (int i = 1; i <= d; i++) {
                int t = n % 9;
                ans *= t;
            }

            ans %= 9;

            if (ans == 0)
                ans = 9;

            printf("%d\n", ans);
        }
    }


    return 0;
}
