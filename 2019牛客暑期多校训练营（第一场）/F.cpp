#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 100000+10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
ll cross(pll a,pll b){
    return a.X*b.Y-a.Y*b.X;
}
ll get_area(pll a,pll b,pll c){
    return abs(cross(a,b)+cross(b,c)+cross(c,a));
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    pll a,b,c;
    while (cin>>a.X>>a.Y>>b.X>>b.Y>>c.X>>c.Y){
        ll ans=get_area(a,b,c)*11;
        cout<<ans<<"\n";
    }
    return 0;
}
