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
const int mod = 1e9+7;

int a[2005][2005];
int n,m;
inline int f(int x,int y) {
    if(x-y>n||y-x>m) return 0;
    if(x==0||y==0) return 1;
    if(a[x][y]) return a[x][y];
    a[x][y]=f(x-1,y)+f(x,y-1);
    if(a[x][y]>=mod) a[x][y]-=mod;
    return a[x][y];
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(;cin>>n>>m;) {
        for(int i=0;i<=n+m;i++) {
            for(int j=i;j<=n+m;j++) {
                a[i][j]=a[j][i]=0;
            }
        }
        cout<<f(n+m,n+m)<<"\n";
    }
    return 0;
}
