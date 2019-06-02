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
const int maxn = 1e3+10;
const int maxm = 2e5+10;
const int N = 1e7 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
inline ll qpow(ll x,int p) {
    ll ans=1;
    for(;p;p>>=1) {
        if(p&1) ans=(ans*x)%mod;
        x=x*x%mod;
    }
    return ans;
}
ll a[maxn][maxn];
int f[maxn][maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q,l;
    int x,y;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) {
        cin>>x>>y;
        l=y-x+1;
        ll tmp=1LL*l*(l+1)/2;
        tmp=qpow(tmp,mod-2);
        for(int j=x;j<=y;j++) {
            a[i][j]=1LL*(j-x+1)*(y-j+1)*tmp%mod;
        }
    }
    int t1,t2,t3,t4;
    for(;q--;) {
        cin>>t1>>t2>>t3>>t4;
        f[t1][t2]++;
        f[t3+1][t4+1]++;
        f[t1][t4+1]--;
        f[t3+1][t2]--;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            if(!f[i][j]) {
                ans+=a[i][j];
                if(ans>=mod) ans-=mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
