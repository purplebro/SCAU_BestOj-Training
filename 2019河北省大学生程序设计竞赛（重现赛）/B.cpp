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
const int N = 2e5 + 10;
const int maxn = 1e6 + 10;
const int maxm = 2.5e7 + 10;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const ll mod = 1e9+7;
const double eps = 1e-8;

inline ll qpow(ll x,ll n,ll mod){
    ll ans=1;
    for(;n;n>>=1){
        if(n&1) ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);

    int T;

    scanf("%d", &T);

    for (;T--;) {
        int q,p,n,m;
        ll tmp=0,sum=0,x=1;
        scanf("%d%d%d",&q,&n,&p);
        m=sqrt(n);
        for(int i=1;i<=m;i++) {
            x=x*q%p;
            tmp+=x;
            if(tmp>=p) tmp-=p;
        }
        int i;
        ll bi=qpow(q,m,p);
        for(i=0;i+m<=n;i+=m){
            sum+=tmp;
            if(sum>=p) sum-=p;
            tmp=tmp*bi%p;
        }
        tmp=qpow(q,i,p);
        for(int j=i+1;j<=n;j++) {
            tmp=tmp*q%p;
            sum=sum+tmp;
            if(sum>=p) sum-=p;
        }
        printf("%lld\n",sum);
    }

    return 0;
}
