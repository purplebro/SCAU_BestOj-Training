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
const int maxn = 1000+10;
const int maxm = 3e5+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
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
int qpow(int a,int b){
    int res=1,base=a;
    while (b){
        if (b&1) res=1ll*res*base%mod;
        base=1ll*base*base%mod;
        b>>=1;
    }
    return res;
}
int fac[maxn],inv[maxn];
int dp[maxn];
int get_dp(int n){
    if (n<=1) return 1;
    if (~dp[n]) return dp[n];
    int res=0;
    for (int i=2;i<=n;i+=2){
        res=(1ll*res+1ll*get_dp(i-1)*get_dp(n-i)%mod*inv[i-1]%mod*inv[n-i]%mod)%mod;
    }
    res=1ll*res*fac[n-1]%mod;
    return dp[n]=res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    fac[0]=inv[0]=1;
    for (int i=1;i<=1000;i++) {
        fac[i]=1ll*fac[i-1]*i%mod;
        inv[i]=qpow(fac[i],mod-2);
    }
    mst(dp,-1);
    int n; cin>>n;
    cout<<get_dp(n)<<"\n";
    return 0;
}
