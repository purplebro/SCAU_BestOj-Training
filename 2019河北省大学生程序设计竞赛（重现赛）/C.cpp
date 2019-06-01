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

ll dp[105][105];
ll a[105];
inline ll f(int x,int y){
    if(x==y) return 0;
    if(~dp[x][y]) return dp[x][y];
    ll tmp;
    tmp=min(a[x]*(y-x)+f(x+1,y),a[y]*(y-x)+f(x,y-1));
    for(int i=x+1;i<y;i++) {
        tmp=min(tmp,a[i]*(y-x)+f(x,i-1)+f(i+1,y));
    }
    return dp[x][y]=tmp;
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
        int n;
        scanf("%d",&n);
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        printf("%lld\n",f(1,n));
    }

    return 0;
}
