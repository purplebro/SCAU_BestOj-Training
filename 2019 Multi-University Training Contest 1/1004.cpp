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
const int maxn = 1e5+10;
const int maxm = 1e5+10;
const int inf = 0x3f3f3f3f ;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9+7;
const double PI = acos(-1.);
const double eps = 1e-12;
int sgn(double x){
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return -1;
}
int l[maxn],s[maxn],v[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<setprecision(10)<<fixed;
    int n;
    while (cin>>n){
        for (int i=0;i<=n;i++) cin>>l[i];
        for (int i=0;i<=n;i++) cin>>s[i];
        for (int i=0;i<=n;i++) cin>>v[i];
        int dd=0;
        double ans=0;
        for (int i=0;i<=n;i++){
            if (i) dd+=l[i];
            double res=1.*(s[i]+dd)/(1.*v[i]);
            if (sgn(ans-res)<0) ans=res;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
