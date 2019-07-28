#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
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
#define debug(a) cout << #a": " << a << endl;
const int maxn = 3000000+10;
const int maxm = 10;
const int N = 3e6 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
int a[maxn];
ll sum[maxn],mx[maxn<<2],mn[maxn<<2];
inline void pushup(int o){
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
    mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void build(int o,int L,int R){
    if (L==R){
        mx[o]=mn[o]=sum[L];
        return;
    }
    int M=(L+R)>>1;
    build(o<<1,L,M);
    build(o<<1|1,M+1,R);
    pushup(o);
}
ll query_mn(int o,int L,int R,int ql,int qr){
    if (ql<=L && R<=qr){
        return mn[o];
    }
    int M=(L+R)>>1;
    ll res=INF;
    if (ql<=M) res=min(res,query_mn(o<<1,L,M,ql,qr));
    if (qr>M) res=min(res,query_mn(o<<1|1,M+1,R,ql,qr));
    return res;
}
ll query_mx(int o,int L,int R,int ql,int qr){
    if (ql<=L && R<=qr){
        return mx[o];
    }
    int M=(L+R)>>1;
    ll res=-INF;
    if (ql<=M) res=max(res,query_mx(o<<1,L,M,ql,qr));
    if (qr>M) res=max(res,query_mx(o<<1|1,M+1,R,ql,qr));
    return res;
}
int stk[maxn],top;
int le[maxn],ri[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sum[0]=0;
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        sum[i]=sum[i-1]+x;
    }
    build(1,0,n);
    top=0;
    for (int i=1;i<=n;i++){
        le[i]=i;
        while (top && a[stk[top-1]]>=a[i]){
            le[i]=le[stk[top-1]];
            top--;
        }
        stk[top++]=i;
    }
    top=0;
    for (int i=1;i<=n;i++){
        ri[i]=n;
        while (top && a[stk[top-1]]>a[i]){
            ri[stk[top-1]]=i-1;
            top--;
        }
        stk[top++]=i;
    }
    ll res,ans=-INF;
    for (int i=1;i<=n;i++){
        if (a[i]>0){
            res=query_mx(1,0,n,i,ri[i])-query_mn(1,0,n,le[i]-1,i-1);
        } else {
            res=query_mn(1,0,n,i,ri[i])-query_mx(1,0,n,le[i]-1,i-1);
        }
        ans=max(ans,res*a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
