#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 500+10;
const int maxm = 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
namespace IO {
    const int MX = 1e8;
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

int a[maxn][maxn];
int colMax[maxn];
int colMin[maxn];
int mxq[maxn << 1];
int mnq[maxn << 1];
//list<int> mxq,mnq;
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    IO::begin();
    int n,m;
    int T; IO::read(T);
    while (T--){
        IO::read(n);
        IO::read(m);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                IO::read(a[i][j]);
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                colMax[j] = 0;
                colMin[j] = inf;
            }
            for (int j = i; j <= n; j++) {
//                mxq.clear();
//                mnq.clear();
                int L=1;
                int topMax = 0, rearMax = 0;
                int topMin = 0, rearMin = 0;
                for (int k = 1; k <= n; k++) {
                    colMax[k] = max(colMax[k], a[j][k]);
                    colMin[k] = min(colMin[k], a[j][k]);

                    for (;topMax - rearMax && colMax[mxq[topMax - 1]]<=colMax[k];) topMax--;
                    for (;topMin - rearMin && colMin[mnq[topMin - 1]]>=colMin[k];) topMin--;

//                    mxq.push_back(k);
//                    mnq.push_back(k);

                    mxq[topMax++] = k;
                    mnq[topMin++] = k;

                    for (;L<=k && colMax[mxq[rearMax]]-colMin[mnq[rearMin]]>m;){
                        L++;
                        if (topMax - rearMax && mxq[rearMax]<L) rearMax++;
                        if (topMin - rearMin && mnq[rearMin]<L) rearMin++;
                    }

                    if (topMax - rearMax && topMin - rearMin) res=max(res,(k-L+1)*(j-i+1));
                }

            }
        }
        printf("%d\n", res);
    }
    return 0;
}
