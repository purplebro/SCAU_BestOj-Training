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
const int maxn = 1e5 + 10;
const int maxm = 2.5e7 + 10;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const ll mod = 1e9+7;
const double eps = 1e-8;

int f[maxn],n,id[maxn<<1],a[maxn];
int ans[maxn];
inline void add(int x,int p){
    for(int i=x;i<=n;i+=lb(i)) f[i]+=p;
}
inline int query(int x){
    int ans=0;
    for(int i=x;i;i-=lb(i)) ans+=f[i];
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&x,&y);
        id[x]=i;
        a[i]=y;
    }
    for(int i=1;i<=n;i++) {
        x=id[a[i]];
        add(x,1);
        ans[i]+=i-query(x);
    }
    for(int i=1;i<=n;i++) f[i]=0;
    for(int i=n;i;i--) {
        x=id[a[i]];
        ans[i]+=query(x);
        add(x,1);
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}
