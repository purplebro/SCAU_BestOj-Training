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
const int maxn = 1e5+10;
const int maxm = 1e6+10;
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
pii p[maxn][2];
ll dp[maxn][2];
int dis(pii &a,pii &b){
    return abs(a.X-b.X)+abs(a.Y-b.Y);
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    int n,m; cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++) cin>>p[i][j].X>>p[i][j].Y;
    }
    for (int i=1;i<n;i++){
        for (int j=0;j<2;j++){
            dp[i][j]=min(dp[i-1][j]+dis(p[i][j],p[i-1][j])+dis(p[i][j^1],p[i-1][j^1]),
                         dp[i-1][j^1]+dis(p[i][j],p[i-1][j^1])+dis(p[i][j^1],p[i-1][j]));
        }
    }
    cout<<min(dp[n-1][0],dp[n-1][1])+dis(p[n-1][0],p[n-1][1])<<"\n";
    return 0;
}
