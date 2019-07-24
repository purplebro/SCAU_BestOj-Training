#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
#define lc o<<1
#define rc o<<1|1
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2000000+10;
const int maxm = 100000+10;
const int mod = 998244353;
const double eps = 1e-9;
int qpow(int a,int b){
    int res=1,base=a;
    while (b){
        if (b&1) res=1ll*res*base%mod;
        base=1ll*base*base%mod;
        b>>=1;
    }
    return res;
}
int inv2;
void FWT(int *a,int n){
    for (int d=1;d<n;d<<=1) for (int m=d<<1,i=0;i<n;i+=m) for (int j=0;j<d;j++){
        int x=a[i+j],y=a[i+j+d];
        a[i+j]=(1ll*x+y)%mod;
        a[i+j+d]=(1ll*x-y+mod)%mod;
    }
}
void UFWT(int *a,int n){
    for (int d=1;d<n;d<<=1) for (int m=d<<1,i=0;i<n;i+=m) for (int j=0;j<d;j++){
        int x=a[i+j],y=a[i+j+d];
        a[i+j]=(1ll*x+y)*inv2%mod;
        a[i+j+d]=(1ll*x-y+mod)%mod*inv2%mod;
    }
}
int a[maxn];
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    inv2=qpow(2,mod-2);
    int n;
    while (cin>>n){
        int m=1;
        while ((1<<m)<n) m++;
        for (int i=0;i<(1<<m);i++) a[i]=0;
        for (int i=0;i<n;i++) a[i]=1;
        FWT(a,1<<m);
        for (int i=0;i<(1<<m);i++){
            a[i]=1ll*a[i]*a[i]%mod*a[i]%mod;
        }
        UFWT(a,1<<m);
        int sum=0;
        for (int i=0;i<(1<<m);i++){
            sum=(1ll*sum+1ll*a[i]*i%mod)%mod;
        }
        int ans=0;
        for (int i=0;i<(1<<m);i++){
            ans=(1ll*ans+1ll*a[i]*i%mod*((sum-i+mod)%mod)%mod)%mod;
        }
        ans=1ll*ans*inv2%mod;
        cout<<ans<<"\n";
    }
    return 0;
}
