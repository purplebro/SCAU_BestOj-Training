#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 1000 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;

LL fac[N];
int has[N];
LL p, n, m;
LL ans;
LL phi(LL n) {
    LL ans = n;
    for (LL i = 2; i * i <= n; i++) if (n % i == 0) {
        ans -= ans / i;
        for (; n % i == 0;)
            n /= i;
    }
    if (n > 1)
        ans -= ans / n;
    return ans;
}
inline LL q_pow(LL base, LL b, LL p) {
    LL res = 1;
    for (; b; b >>= 1, base = base * base % p) if (b & 1)
        res = res * base % p;
    return res;
}

int main() {
#ifdef purple_bro
    freopen("in.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;

    cin >> T;

    for (;T--;) {
        cin >> p >> n >> m;

        LL t;

        if (p == 2 || p == 5) {
            cout << 0 << "\n";
            continue;
        }
        if (p == 3){
            t = 18;
            p = 27;
        } else
            t = phi(p * 9);

        LL d = INF;

        for (LL i = 1; i * i <= t; i++) if (t % i == 0) {
            if (q_pow(10, i, p) == 1)
                d = min(d, i);
            if (q_pow(10, t / i, p) == 1)
                d = min(d, t / i);
        }

        int tot = 0;

        for (LL i = 2; i * i <= d; i++) if (d % i == 0) {
            int cnt = 0;
            for (; d % i == 0;) {
                d /= i;
                cnt++;
            }
            fac[++tot] = i;
            has[tot] = cnt;
        }

        if (d != 1) {
            fac[++tot] = d;
            has[tot] = 1;
        }

        ans = 0;
        LL sum = 1;

        for (int j = 1; j <= min(1LL * 30, m); j++) {
            sum = 1;
            for (int i = 1; i <= tot; i++) {
                int limit = has[i] / j + (has[i] % j != 0);
                sum *= q_pow(fac[i], limit, p);
            }
            ans += n / sum;
        }

        if (m > 30)
            ans += 1LL * (n / sum) * (m - 30);

        for (int i = 1; i <= tot; i++) {
            fac[i] = 0;
            has[i] = 0;
        }

        cout << ans << "\n";
    }

    return 0;
}
