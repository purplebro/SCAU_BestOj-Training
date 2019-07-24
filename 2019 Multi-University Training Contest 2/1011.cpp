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
const int maxn = 1e5+10;
const int maxm = 4e6+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int sum[maxm],L[maxm],R[maxm],id[maxn],cnt;
inline void ins(int &i,int o,int l,int r,int k) {
    sum[i=++cnt]=sum[o]+1;
    if(l==r) return;
    L[i]=L[o]; R[i]=R[o];
    int m=(l+r)>>1;
    if(k<=m) ins(L[i],L[o],l,m,k);
    else ins(R[i],R[o],m+1,r,k);
}
inline int query(int i,int o,int l,int r,int k) {
    if(l==r) return l;
    int m=(l+r)>>1;
    if(k>sum[L[i]]-sum[L[o]]) return query(R[i],R[o],m+1,r,k-(sum[L[i]]-sum[L[o]]));
    else return query(L[i],L[o],l,m,k);
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y,len,t1,t2,t3;
    ll ans;
    for(;cin>>n>>m;) {
        cnt=0;
        for(int i=1;i<=n;i++) {
            cin>>x;
            ins(id[i],id[i-1],1,1e9,x);
        }
        for(;m--;) {
            cin>>x>>y;
            len=y-x+1;
            ans=-1;
            for(int i=len;i>=3;i--) {
                t1=query(id[y],id[x-1],1,1e9,i);
                t2=query(id[y],id[x-1],1,1e9,i-1);
                t3=query(id[y],id[x-1],1,1e9,i-2);
                if(t2+t3>t1) {
                    ans=t2+t3;
                    ans+=t1;
                    break;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
