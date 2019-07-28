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
const int maxn = 1e3+10;
const int maxm = 1e5+10;
const int inf = 0x3f3f3f3f ;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
pii a[maxn];
double cal(int x0,int y0,int x1,int y1,int x){
    ll tmp=1ll*(x-x0)*(y1-y0);
    double res=1.*tmp/(x1-x0);
    res+=y0;
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int hehe=100000000;
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        for (int i=0;i<n;i++) cin>>a[i].X>>a[i].Y;
        sort(a,a+n);
        int p1=n/2-1,p2=n/2;
        if (a[p1].X!=a[p2].X){
            cout<<a[p1].X<<" "<<-hehe<<" "<<a[p2].X<<" "<<hehe<<"\n";
        } else {
            double tmp=cal(a[p1].X-1,hehe,a[p1].X,a[p1].Y,a[p1].X+1);
            int L=ceil(tmp);
            tmp=cal(a[p1].X-1,hehe,a[p2].X,a[p2].Y,a[p2].X+1);
            int R=floor(tmp);
            assert(L<=R);
            cout<<a[p1].X-1<<" "<<hehe<<" "<<a[p1].X+1<<" "<<(L+R)/2<<"\n";
        }
    }
    return 0;
}
