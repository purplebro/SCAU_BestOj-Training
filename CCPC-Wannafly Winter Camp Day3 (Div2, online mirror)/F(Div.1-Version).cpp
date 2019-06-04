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
const int N = 1e7 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-4;

int mu[N];
int phi[N];
int prime[N];
bool vis[N];
int cnt;

inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
void sieve() {
    mu[1] = phi[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            mu[i] = mod - 1;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && 1LL * prime[j] * i < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            mu[i * prime[j]] = (-mu[i] + mod) % mod;
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    for (int i = 1; i < N; i++)
        add(mu[i], mu[i - 1]), add(phi[i], phi[i - 1]);
}
unordered_map<LL, int> mpMu, mpPhi;
int getMu(LL n) {
    if (n < N)
        return mu[n];
    if (mpMu.find(n) != mpMu.end())
        return mpMu[n];
    int res = 0;
    for (LL i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        add(res, 1LL * (j - i + 1) * getMu(n / i) % mod);
    }
    return mpMu[n] = (1 - res + mod) % mod;
}
LL getPre(LL n) {
    n %= mod;
    return n * (n + 1) / 2;
}
int getPhi(LL n) {
    if (n < N)
        return phi[n];
    if (mpPhi.find(n) != mpPhi.end())
        return mpPhi[n];
    int res = 0;
    for (LL i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        add(res, 1LL * (j - i + 1) * getPhi(n / i) % mod);
    }
    return mpPhi[n] = (getPre(n) - res + mod) % mod;
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    sieve();

    LL n;

    scanf("%lld", &n);

    int res = 0;

    for (LL i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        int p = (2LL * getPhi(n / i) - 1 + mod) % mod;
        add(res, 1LL * (getMu(j) - getMu(i - 1) + mod) % mod * p % mod);
    }

    printf("%d\n", res);

    return 0;
}
