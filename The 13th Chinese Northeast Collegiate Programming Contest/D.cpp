#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 500000+10;
const int maxm = 4000+10;
const int mod = 998244353;
const double eps = 1e-9;
struct Query{
    int op,u,v,k;
    Query(int op=0,int u=0,int v=0,int k=0):op(op),u(u),v(v),k(k){}
}q[maxm];
vector<int> E[maxn];
int pre[20][maxn],dep[maxn],dfn[maxn],idx;
void dfs(int u,int fa){
    dfn[u]=idx++;
    pre[0][u]=fa;
    for (int i=1;i<20;i++){
        pre[i][u]=pre[i-1][pre[i-1][u]];
    }
    for (int v:E[u]){
        if (v==fa) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
pii LCA(int u,int v){
    if (dep[u]<dep[v]) swap(u,v);
    int c=dep[u]-dep[v];
    for (int d=dep[u]-dep[v],i=0;d;d>>=1,i++){
        if (d&1) u=pre[i][u];
    }
    if (u==v) return pii(u,c-1);
    for (int i=19;i>=0;i--){
        if (pre[i][u]!=pre[i][v]){
            u=pre[i][u];
            v=pre[i][v];
            c+=(1<<(i+1));
        }
    }
    return pii(pre[0][u],c+1);
}
struct Edge{
    int to,next,c,w;
    Edge(){}
}edge[maxm<<2];
int head[maxn],tot;
void addedge(int u,int v,int c,int w=0){
//    cout<<u<<" "<<v<<" "<<c<<endl;
    assert(c>=0);
    edge[tot].to=v;
    edge[tot].c=c;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}
int node[maxm],node_num;
stack<int> stk;
void build(){
    for (int i=0;i<node_num;i++){
        int lca,c;
        if (!stk.empty() && (lca=LCA(stk.top(),node[i]).X)!=stk.top()){
            int x=stk.top(); stk.pop();
            while (!stk.empty() && dfn[stk.top()]>dfn[lca]){
                c=LCA(stk.top(),x).Y;
                addedge(stk.top(),x,c);
                addedge(x,stk.top(),c);
                x=stk.top(); stk.pop();
            }
            c=LCA(lca,x).Y;
            addedge(lca,x,c);
            addedge(x,lca,c);
            if (stk.empty() || stk.top()!=lca) stk.push(lca);
        }
        stk.push(node[i]);
    }
    int x=stk.top(); stk.pop();
    while (!stk.empty()){
        int c=LCA(stk.top(),x).Y;
        addedge(stk.top(),x,c);
        addedge(x,stk.top(),c);
        x=stk.top(); stk.pop();
    }
}
int path[maxn],w[maxn];
bool get_path(int u,int x,int fa){
    if (u==x) return true;
    for (int i=head[u];~i;i=edge[i].next){
        int v=edge[i].to;
        if (v==fa) continue;
        if (get_path(v,x,u)){
            path[u]=i;
            return true;
        }
    }
    return false;
}
void update(int op,int id,int k){
//    cout<<id<<" ";
    if (op==1){
        w[id]+=k;
        edge[path[id]].w+=k;
        edge[path[id]^1].w+=k;
    } else if (op==2){
        w[id]^=k;
        edge[path[id]].w^=k;
        edge[path[id]^1].w^=k;
    } else {
        if (w[id]>=k){
            w[id]-=k;
        }
        if (edge[path[id]].w>=k){
            edge[path[id]].w-=k;
            edge[path[id]^1].w-=k;
        }
    }
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n,m; cin>>n>>m;
        tot=0;
        for (int i=1;i<=n;i++) {
            E[i].clear();
            head[i]=path[i]=-1;
            w[i]=0;
        }
        for (int i=0;i<n-1;i++){
            int u,v; cin>>u>>v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        idx=0;
        dfs(1,1);
        node_num=0;
        for (int i=0;i<m;i++){
            int op,u,v; cin>>op>>u>>v;
            if (op<4 || op==7){
                int k; cin>>k;
                q[i]=Query(op,u,v,k);
            } else q[i]=Query(op,u,v);
            node[node_num++]=u;
            node[node_num++]=v;
        }
        sort(node,node+node_num,[](const int &l,const int &r){return dfn[l]<dfn[r];});
        node_num=unique(node,node+node_num)-node;
        build();
        for (int i=0;i<m;i++){
            int op=q[i].op,u=q[i].u,v=q[i].v,k=q[i].k;
            get_path(u,v,u);
            int cur=u;
            if (op<=3){
                while (~path[cur]){
                    update(op,cur,k);
                    cur=edge[path[cur]].to;
                }
                update(op,cur,k);
            } else {
                ll sum=0;
                int mx=-inf,mn=inf,_mn=inf,xor_sum=0;
                while (~path[cur]){
                    int id=path[cur];
                    sum+=1ll*edge[id].w*edge[id].c+w[cur];
                    xor_sum^=w[cur]^((edge[id].c&1)?edge[id].w:0);
                    mx=max({mx,w[cur],(edge[id].c?edge[id].w:-inf)});
                    mn=min({mn,w[cur],(edge[id].c?edge[id].w:inf)});
                    _mn=min({_mn,abs(w[cur]-k),(edge[id].c?abs(edge[id].w-k):inf)});
                    cur=edge[path[cur]].to;
                }
                sum+=w[cur];
                xor_sum^=w[cur];
                mx=max(mx,w[cur]);
                mn=min(mn,w[cur]);
                _mn=min(_mn,abs(w[cur]-k));
                if (op==4) cout<<sum<<"\n"; else
                if (op==5) cout<<xor_sum<<"\n"; else
                if (op==6) cout<<mx-mn<<"\n"; else  cout<<_mn<<"\n";
            }
            while (~path[u]){
                int nx=edge[path[u]].to;
                path[u]=-1;
                u=nx;
            }
//            for (int i=1;i<=n;i++) cout<<w[i]<<" "; cout<<endl;
        }
    }
    return 0;
}
