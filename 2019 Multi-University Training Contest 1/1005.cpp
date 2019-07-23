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
const int mod = 1e9+7;
const double PI = acos(-1.);

inline void read(int &x) {
    x=0; char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
struct edge{
    int to,n;
    ll c;
}e1[maxm],e2[maxm];
int head1[maxn],head2[maxn],tot1,tot2,n;
ll dis1[maxn],dis2[maxn],vis[maxn];
inline void init() {
    tot1=tot2=0;
    for(int i=1;i<=n;i++) head1[i]=head2[i]=0;
}
inline void add1(int x,int y,int c) {
    e1[++tot1].to=y;
    e1[tot1].c=c;
    e1[tot1].n=head1[x];
    head1[x]=tot1;
}
inline void add2(int x,int y,int c) {
    e2[++tot2].to=y;
    e2[tot2].c=c;
    e2[tot2].n=head2[x];
    head2[x]=tot2;
}
priority_queue<pli> q;
inline void dij2(int x) {
    for(int i=1;i<=n;i++) {
        vis[i]=false;
        dis2[i]=INF;
    }
    dis2[x]=0;
    q.push(pli(0,x));
    int u,v;
    for(;!q.empty();) {
        u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head2[u];i;i=e2[i].n) {
            v=e2[i].to;
            if(dis2[v]>dis2[u]+e2[i].c) {
                dis2[v]=dis2[u]+e2[i].c;
                q.push(pli(-dis2[v],v));
            }
        }
    }
}
inline void dij1(int x) {
    for(int i=1;i<=n;i++) {
        vis[i]=false;
        dis1[i]=INF;
    }
    dis1[x]=0;
    q.push(pli(0,x));
    int u,v;
    for(;!q.empty();) {
        u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head1[u];i;i=e1[i].n) {
            v=e1[i].to;
            if(dis1[v]>dis1[u]+e1[i].c) {
                dis1[v]=dis1[u]+e1[i].c;
                q.push(pli(-dis1[v],v));
            }
        }
    }
}
queue<int> qu;
inline bool bfs() {
    for(int i=1;i<=n;i++) vis[i]=false,dis1[i]=inf;
    vis[1]=true;
    qu.push(1);
    dis1[1]=0;
    while(!qu.empty()) {
        int u=qu.front(); qu.pop();
        for(int i=head2[u];i;i=e2[i].n) {
            int v=e2[i].to;
            if(!vis[v]&&e2[i].c) {
                dis1[v]=dis1[u]+1;
                vis[v]=true;
                qu.push(v);
            }
        }
    }
    return vis[n];
}
inline ll dfs(int u,ll del) {
    if(u==n) {
        return del;
    }
    ll ret=0;
    for(int i=head2[u];del&&i;i=e2[i].n) {
        if(e2[i].c&&dis1[e2[i].to]==dis1[u]+1) {
            ll d=dfs(e2[i].to,min(del,e2[i].c));
            e2[i].c-=d;
            e2[i^1].c+=d;
            del-=d;
            ret+=d;
        }
    }
    return ret;
}
inline ll dinic() {
    ll ret=0;
    while(bfs()) {
        ret+=dfs(1,INF);
    }
    return ret;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T; read(T);
    int m,x,y,c;
    while (T--) {
        read(n); read(m);
        init();
        for(int i=1;i<=m;i++) {
            read(x); read(y); read(c);
            add1(x,y,c);
            add2(y,x,c);
        }
        dij2(n);
        dij1(1);
        for(int i=1;i<=n;i++) head2[i]=0; tot2=1;
        for(int i=1;i<=n;i++) {
            for(int j=head1[i];j;j=e1[j].n) {
                if(dis1[i]+dis2[e1[j].to]+e1[j].c==dis1[n]) {
                    add2(i,e1[j].to,e1[j].c);
                    add2(e1[j].to,i,0);
                }
            }
        }
        printf("%lld\n",dinic());
    }
    return 0;
}
