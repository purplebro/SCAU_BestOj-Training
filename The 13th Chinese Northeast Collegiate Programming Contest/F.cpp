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
const int maxn = 2e5+10;
const int maxm = 2e5+10;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to,next;
}edge[maxm];
int head[maxn],tot;
int deg[maxn][6],dp[maxn][6];
//bool allwin[maxn][6],alllost[maxn][6];
void init(int n){
    for (int i=1;i<=n;i++) {
        head[i]=-1;
        for (int j=0;j<6;j++) {
            deg[i][j]=0;
            dp[i][j]=-1;
//            allwin[i][j]=alllost[i][j]=true;
        }
    }
    tot=0;
}
void addedge(int u,int v){
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}
char s[maxn],s1[maxn];
struct node{
    int u,k,sta;
    node (int u=0,int k=0,int sta=0):u(u),k(k),sta(sta){}
};
void solve(int n){
    queue<node> q;
    for (int i=1;i<=n;i++){
        for (int j=0;j<6;j++){
            if (deg[i][j]==0){
                dp[i][j]=0;
                q.push(node(i,j,0));
            }
        }
    }
    while (!q.empty()){
        node x=q.front(); q.pop();
        int pre=(x.k-1+6)%6;
        if (s1[pre]=='0'){
            if (s[x.k]==s[pre]){
                if (x.sta){
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre]) continue;
                        dp[v][pre]=1;
    //                    alllost[v][pre]=false;
                        q.push(node(v,pre,1));
                    }
                } else {
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre] || deg[v][pre]>0) continue;
                        dp[v][pre]=0;
                        q.push(node(v,pre,0));
                    }
                }
            } else {
                if (x.sta){
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre] || deg[v][pre]>0) continue;
                        dp[v][pre]=0;
                        q.push(node(v,pre,0));
                    }
                } else {
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre]) continue;
                        dp[v][pre]=1;
                        q.push(node(v,pre,1));
                    }
                }
            }
        } else {
            if (s[x.k]==s[pre]){
                if (x.sta){
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre] || deg[v][pre]>0) continue;
                        dp[v][pre]=1;
    //                    alllost[v][pre]=false;
                        q.push(node(v,pre,1));
                    }
                } else {
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre]) continue;
                        dp[v][pre]=0;
                        q.push(node(v,pre,0));
                    }
                }
            } else {
                if (x.sta){
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre]) continue;
                        dp[v][pre]=0;
                        q.push(node(v,pre,0));
                    }
                } else {
                    for (int i=head[x.u];~i;i=edge[i].next){
                        int v=edge[i].to;
                        deg[v][pre]--;
                        if (~dp[v][pre] || deg[v][pre]>0) continue;
                        dp[v][pre]=1;
                        q.push(node(v,pre,1));
                    }
                }
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n,m; cin>>n>>m;
        init(n);
        for (int i=0;i<m;i++){
            int u,v; cin>>u>>v;
            addedge(v,u);
            for (int j=0;j<6;j++) deg[u][j]++;
        }
        cin>>s>>s1;
        solve(n);
        for (int i=1;i<=n;i++){
            if (dp[i][0]==-1) cout<<'D'; else {
                if (dp[i][0]==1) cout<<s[0]; else {
                    if (s[0]=='A') cout<<'B'; else cout<<'A';
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
