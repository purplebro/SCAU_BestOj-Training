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
const int maxm = 3e5+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
//namespace IO {
//    const int MX = 4e7;
//    char buf[MX];
//    int c, sz;
//    void begin() {
//        c = 0;
//        sz = fread(buf, 1, MX, stdin);
//    }
//    inline bool read(int &t) {
//        for (;c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9');) c++;
//        if (c >= sz)
//            return false;
//        bool flag = 0;
//        if (buf[c] == '-') {
//            flag = 1;
//            c++;
//        }
//        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
//            t = t * 10 + buf[c] - '0';
//        if (flag)
//            t = -t;
//        return true;
//    }
//}
int val[maxn],f[maxn];
vector<int> E[maxn];
ll dp[maxn],dp1[maxn];
void dfs(int u,int fa){
    ll mx=-INF;
    f[u]=fa;
    for (int v:E[u]){
        if (v==fa) continue;
        dfs(v,u);
        mx=max(mx,dp[v]);
    }
    dp[u]=val[u];
    if (mx>0) dp[u]+=mx;
}
ll pre[maxn],suf[maxn],a[maxn];
void bfs(){
    queue<int> q;
    q.push(1);
    dp1[1]=val[1];
    while (!q.empty()){
        int u=q.front(); q.pop();
        int fa=f[u];
        int tot=0;
        for (int v:E[u]){
            if (v==fa) continue;
            a[++tot]=dp[v];
            q.push(v);
        }
        pre[0]=-INF;
        for (int i=1;i<=tot;i++) pre[i]=max(pre[i-1],a[i]);
        suf[tot+1]=-INF;
        for (int i=tot;i>=1;i--) suf[i]=max(suf[i+1],a[i]);
        int j=0;
        for (int v:E[u]){
            if (v==fa) continue;
            j++;
            ll mx=max(pre[j-1],suf[j+1]),vv=val[u];
            if (mx>0) vv+=mx;
            vv=max(vv,dp1[u]);
            dp1[v]=val[v];
            if (vv>0) dp1[v]+=vv;
        }
    }
}
ll query(int u){
    vector<ll> tmp;
    for (int v:E[u]){
        if (v==f[u]) continue;
        tmp.push_back(dp[v]);
    }
//    tmp.push_back(dp1[u]);
    sort(tmp.begin(),tmp.end());
//    for (int v:tmp) cout<<v<<" "; cout<<endl;
    ll res1=val[u];
    for (int i=tmp.size()-1,j=0;i>=0 && j<4 && tmp[i]>0;i--,j++){
        res1+=tmp[i];
    }
    ll res2=dp1[u];
    for (int i=tmp.size()-1,j=0;i>=0 && j<3 && tmp[i]>0;i--,j++){
        res2+=tmp[i];
    }
    return max(res1,res2);
}
void output(ll x){
    if (!x) return;
    output(x/2);
    cout<<x%2;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    int n; cin>>n;
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        if (x==0) val[i]=0; else {
            if (x>0) {
                val[i]=(1<<(x-1));
            } else {
                x=-x;
                val[i]=-(1<<(x-1));
            }
        }
    }
    for (int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,1);
    bfs();
//    for (int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
//    for (int i=1;i<=n;i++) cout<<dp1[i]<<" "; cout<<endl;
    int q; cin>>q;
    for (int i=0;i<q;i++){
        int u; cin>>u;
        ll ans=query(u);
        if (ans<0) {
            cout<<'-';
            ans=-ans;
        }
        if (ans==0) cout<<0; else output(ans);
        cout<<"\n";
    }
    return 0;
}
