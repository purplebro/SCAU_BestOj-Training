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
const int maxn = 400000+10;
const int maxm = 10;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
char s[maxn];
int sa[maxn],rak[maxn],Height[maxn],tax[maxn],tp[maxn];
int n,m;
void RSort(){
    for (int i=0;i<=m;i++) tax[i]=0;
    for (int i=1;i<=n;i++) tax[rak[tp[i]]]++;
    for (int i=1;i<=m;i++) tax[i]+=tax[i-1];
    for (int i=n;i>=1;i--) sa[tax[rak[tp[i]]]--]=tp[i];
}
int cmp(int *f,int x,int y,int w){
    return x+w<=n && y+w<=n && f[x]==f[y] && f[x+w]==f[y+w];
}
void getSA(){
    for (int i=1;i<=n;i++) rak[i]=s[i],tp[i]=i;
    m=127,RSort();
    for (int w=1,p=1,i;p<n;w+=w,m=p){
        for (p=0,i=n-w+1;i<=n;i++) tp[++p]=i;
        for (i=1;i<=n;i++) if (sa[i]>w) tp[++p]=sa[i]-w;
        RSort(),swap(rak,tp),rak[sa[1]]=p=1;
        for (int i=2;i<=n;i++)
            rak[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
    }
    int j,k=0;
    for (int i=1;i<=n;Height[rak[i++]]=k)
        for (k=k?k-1:k,j=sa[rak[i]-1];s[i+k]==s[j+k];k++);
}
const int S = 26;
int all, son[N][S], fail[N], cnt[N], len[N], text[N], last, tot;
inline int newNode(int l) {
    for (int i = 0; i < S; i++)
        son[tot][i] = 0;
    cnt[tot] = 0;
    len[tot] = l;
    return tot++;
}
void init() {
    last = tot = all = 0;
    newNode(0), newNode(-1);
    text[0] = -1;
    fail[0] = 1;
}
int getFail(int x) {
    for (;text[all - len[x] - 1] != text[all];)
        x = fail[x];
    return x;
}
void extend(int w) {
    text[++all] = w;
    int x = getFail(last);
    if (!son[x][w]) {
        int y = newNode(len[x] + 2);
        fail[y] = son[getFail(fail[x])][w];
        son[x][w] = y;
    }
    cnt[last = son[x][w]]++;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    init();
    n=strlen(s+1);
    int m=n;
    for (int i = 1; i <= n; i++){
        extend(s[i] - 'a');
    }
    s[n+1]='$';
    for (int i=n+2;i<=n+n+1;i++){
        s[i]=s[2*n-i+2];
    }
    n=2*n+1;
    s[n+1]=0;
    getSA();
    ll ans=0;
    for (int i=1;i<=n;i++){
        ans+=n-sa[i]+1-Height[i];
    }
    ans-=1ll*(n/2+1)*(n/2+1);
    tot-=2;
//    cout<<ans<<" "<<tot<<endl;
//    assert((ans&1) == (tot&1));
//    cout<<ans<<" "<<tot<<endl;
    cout << (ans + tot) / 2 << "\n";

    return 0;
}
