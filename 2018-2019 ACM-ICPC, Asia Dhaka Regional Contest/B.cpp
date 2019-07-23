#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define ls rt<<1
#define rs rt<<1|1
#define lb(x) (x&-x)
#define ALL(x) begin(), end()
const int maxn = 2e6+10;
const int maxm = 2e6+10;
const int N = 1e4 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
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
    inline bool readl(ll &t) {
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
int tot;
ll f[20];
vector<int> c;
map<ll,int> h;
map<int,ll> g;
void dfs(int cur,int d){
    if (d==0){
        ll res=0;
        for (int i=0;i<10;i++){
            res+=c[i]*f[i];
        }
        h[res]=tot;
        g[tot]=res;
        tot++;
        return;
    }
    for (int i=cur;i<10;i++){
        c[i]++;
        dfs(i,d-1);
        c[i]--;
    }
}
int a[20];
pll dp[15][maxn];
pll dfs1(int pos,int sta,bool lead,bool limit){
    if (pos==-1) return pii(0,1);
    if (!limit && !lead && ~dp[pos][sta].X) return dp[pos][sta];
    int up=limit?a[pos]:9,cc[10],sum=0;
    ll tmp=g[sta],res=0,cnt=0,nx;
    for (int i=0;i<10;i++){
        cc[i]=tmp%15;
        tmp/=15;
    }
    tmp=g[sta];
    pll hehe;
    for (int i=0;i<=up;i++){
        if (lead && !i) nx=tmp; else nx=tmp+f[i];
        hehe=dfs1(pos-1,h[nx],lead && !i,limit && i==a[pos]);
        cnt+=hehe.Y;
        res+=1ll*sum*hehe.Y+hehe.X;
        sum+=cc[i];
    }
    if (!limit && !lead){
        dp[pos][sta].X=res;
        dp[pos][sta].Y=cnt;
    }
    return pll(res,cnt);
}
ll solve(ll x){
    int pos=0;
    while (x){
        a[pos++]=x%10;
        x/=10;
    }
    return dfs1(pos-1,h[0],true,true).X;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    IO::begin();
    f[0]=1;
    for (int i=1;i<=10;i++) f[i]=f[i-1]*15;
    mst(dp,-1);
    c.resize(10);
    for (int i=0;i<=14;i++){
        dfs(0,i);
    }
    int T,cas=1; IO::read(T);
    for (;T--;){
        ll x,y; IO::readl(x); IO::readl(y);
        printf("Case %d: %lld\n",cas++,solve(y)-solve(x-1));
    }
    return 0;
}
