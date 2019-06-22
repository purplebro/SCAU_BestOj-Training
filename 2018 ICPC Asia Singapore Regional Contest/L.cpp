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
const int maxn = 2e6+10;
const int maxm = 2e5+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
namespace IO {
    const int MX = 4e7;
    char buf[MX];
    int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        for (;c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9');) c++;
        if (c >= sz)
            return false;
        bool flag = 0;
        if (buf[c] == '-') {
            flag = 1;
            c++;
        }
        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
            t = t * 10 + buf[c] - '0';
        if (flag)
            t = -t;
        return true;
    }
}

int prime[N];
int cnt;
int f[N];
bool vis[N];

void sieve() {
    f[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            prime[cnt++] = i;
            f[i] = i;
        }
        for (int j = 0; j < cnt && 1LL * i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            f[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    IO::begin();

    sieve();

    int T;

    IO::read(T);

    for (;T--;) {
        int n;

        IO::read(n);

        int num = 1;
        int p = 0;

        for (; n != 1;) {
            int t = 0;
            int g = f[n];
            for (; n % g == 0; t++)
                n /= g;
            num *= t + 1;
            p++;
        }

        printf("%d\n", num - p);
    }

    return 0;
}
