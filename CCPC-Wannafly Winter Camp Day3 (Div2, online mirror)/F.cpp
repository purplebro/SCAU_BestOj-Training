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
const int maxn = 2e5+10;
const int maxm = 2e5+10;
const int N = 1e7 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int prime[N];
bool vis[N];
int cnt;
int mu[N];
int f[N];
int low[N];
int times[N];

inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
void sieve(int n) {
    mu[1] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = mod - 1;
            times[i] = 1;
            low[i] = i;
            f[i] = mod - 2;
        }
        for (int j = 0; j < cnt && 1LL * prime[j] * i <= n; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                low[i * prime[j]] = low[i] * prime[j];
                times[i * prime[j]] = times[i] + 1;
                if (low[i] == i && times[i] == 1)
                    f[i * prime[j]] = 1;
                else if (low[i] != i)
                    f[i * prime[j]] = 1LL * f[i / low[i]] * f[low[i] * prime[j]] % mod;
                break;
            }
            low[i * prime[j]] = prime[j];
            times[i * prime[j]] = 1;
            mu[i * prime[j]] = (-mu[i] + mod) % mod;
            f[i * prime[j]] = 1LL * f[i] * f[prime[j]] % mod;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n;

    scanf("%d", &n);

    sieve(n);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int t = 1LL * (n / i) * (n / i) % mod;
        add(ans, 1LL * t * f[i] % mod);
    }

    printf("%d\n", ans);

    return 0;
}
