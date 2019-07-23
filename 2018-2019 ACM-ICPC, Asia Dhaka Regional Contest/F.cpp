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
const int maxn = 1e4+10;
const int maxm = 2e4+10;
const int N = 1e4 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

struct edge{
    int to,n;
}e[maxm];
int tot,head[maxn],k;
int top[maxn],son[maxn],fa[maxn],siz[maxn],dep[maxn],id[maxn],dfn[maxn],cnt;
inline void init(int n) {
    tot=0; cnt=0;
    for(int i=1;i<=n;i++) head[i]=0;
}
inline void add_edge(int x,int y) {
    e[++tot].to=y;
    e[tot].n=head[x];
    head[x]=tot;
}
inline void dfs1(int u,int f,int deep) {
    siz[u]=1;
    fa[u]=f;
    dep[u]=deep;
    son[u]=0;
    for(int i=head[u];i;i=e[i].n) {
        int v=e[i].to;
        if(v==f) continue;
        dfs1(v,u,deep+1);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]]) son[u]=v;
    }
}
inline void dfs2(int u,int t) {
    id[u]=++cnt;
    dfn[cnt]=u;
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(int i=head[u];i;i=e[i].n) {
        int v=e[i].to;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
int mx[maxn<<2],lazy[maxn<<2],num[maxn<<2];
bool sam[maxn<<2];
inline void build(int l,int r,int rt) {
    num[rt]=mx[rt]=lazy[rt]=0;
    sam[rt]=1;
    if(l==r) return;
    int m=(l+r)>>1;
    build(l,m,ls); build(m+1,r,rs);
}
inline void clr(int l,int r,int rt){
    if(!mx[rt]) return;
    num[rt]=mx[rt]=lazy[rt]=0;
    sam[rt]=1;
    if(l==r) return;
    int m=(l+r)>>1;
    clr(l,m,ls); clr(m+1,r,rs);
}
inline void pushdown(int rt) {
    if(lazy[rt]) {
        mx[ls]+=lazy[rt];
        mx[rs]+=lazy[rt];
        lazy[ls]+=lazy[rt];
        lazy[rs]+=lazy[rt];
        lazy[rt]=0;
    }
}
inline void update(int L,int R,int l,int r,int rt,int val) {
    if(L<=l&&r<=R) {
        mx[rt]+=val;
        lazy[rt]+=val;
        if(mx[rt]==k) {
            if(sam[rt]) {
                num[rt]=r-l+1;
                return;
            }
            pushdown(rt);
            int m=(l+r)>>1;
            update(l,m,l,m,ls,0);
            update(m+1,r,m+1,r,rs,0);
            num[rt]=num[ls]+num[rs];
            return;
        }
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,l,m,ls,val);
    if(R>m) update(L,R,m+1,r,rs,val);
    if(sam[ls]&&sam[rs]&&mx[ls]==mx[rs]) sam[rt]=1; else sam[rt]=0;
    mx[rt]=max(mx[ls],mx[rs]);
    num[rt]=num[rs]+num[ls];
    return;
}
inline void updatedis(int x,int y,int val) {
    for(;top[x]!=top[y];) {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(id[top[x]],id[x],1,cnt,1,val);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update(id[x],id[y],1,cnt,1,val);
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,m;
    int x,y;
    cin>>T;
    for(int j=1;j<=T;j++) {
        cout<<"Case "<<j<<":\n";
        cin>>n;
        init(n);
        for(int i=1;i<n;i++) {
            cin>>x>>y;
            add_edge(x,y);
            add_edge(y,x);
        }
        dfs1(1,0,1);
        dfs2(1,1);
        build(1,cnt,1);
        cin>>m;
        for(;m--;) {
            clr(1,cnt,1);
            cin>>k;
            for(int i=0;i<k;i++) {
                cin>>x>>y;
                updatedis(x,y,1);
            }
            cout<<num[1]<<"\n";
        }
    }
    return 0;
}
