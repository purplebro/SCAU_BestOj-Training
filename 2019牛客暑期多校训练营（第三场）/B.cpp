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
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
char s[maxn];
int cnt[2],a[maxn],pos[maxn<<1];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int off=100000;
    int n; cin>>n;
    cin>>(s+1);
    for (int i=1;i<=n;i++){
        cnt[s[i]-'0']++;
        a[i]=cnt[0]-cnt[1];
    }
    mst(pos,-1);
    pos[off]=0;
    int ans=0;
    for (int i=1;i<=n;i++){
        if (~pos[a[i]+off]){
            ans=max(ans,i-pos[a[i]+off]);
        } else pos[a[i]+off]=i;
    }
    cout<<ans<<" "<<min(cnt[0],cnt[1])*2<<"\n";
    return 0;
}
