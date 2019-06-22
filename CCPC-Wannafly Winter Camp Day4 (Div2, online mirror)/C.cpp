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
const int maxm = 3e5+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
//namespace IO {
//    const int MX = 4e7;
//    char buf[MX];
//    int c, sz;
//    void begin() {
//        c = 0;
//        sz = fread(buf, 1, MX, stdin);
//    }
//    inline bool read(int &t) {
//        for (;c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9');) c++;
//        if (c >= sz)
//            return false;
//        bool flag = 0;
//        if (buf[c] == '-') {
//            flag = 1;
//            c++;
//        }
//        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
//            t = t * 10 + buf[c] - '0';
//        if (flag)
//            t = -t;
//        return true;
//    }
//}
int d[maxn];
pii e[maxm];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    int n,m;
    int x,y;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        cin>>x>>y;
        e[i]=pii(x,y);
        d[x]++,d[y]++;
    }
    for(int i=1;i<=n;i++) {
        if(!d[i]) {
            puts("No");
            return 0;
        }
    }
    for(int i=0;i<m;i++) {
        if(d[e[i].X]!=1&&d[e[i].Y]!=1) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
