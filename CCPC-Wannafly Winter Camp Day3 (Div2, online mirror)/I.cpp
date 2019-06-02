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
const int N = 1e7 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int qpow(int a,int b){
    int res=1,base=a;
    while (b){
        if (b&1) res=1ll*res*base%mod;
        base=1ll*base*base%mod;
        b>>=1;
    }
    return res;
}
int f2[maxn],f3[maxn],inv2[maxn],inv3[maxn];
void init(){
    f2[0]=f3[0]=inv2[0]=inv3[0]=1;
    for (int i=1;i<=200000;i++){
        f2[i]=1ll*f2[i-1]*2%mod;
        f3[i]=1ll*f3[i-1]*3%mod;
        inv2[i]=qpow(f2[i],mod-2);
        inv3[i]=qpow(f3[i],mod-2);
    }
}
queue<int> q[maxn];
int v[maxn],c2[maxn],c3[maxn],id[maxn],belong[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n,m; cin>>n>>m;
    for (int i=1;i<=n;i++){
        v[i]=3;
        q[i].push(i);
        id[i]=i;
        belong[i]=i;
    }
    int op;
    for (int i=0;i<m;i++){
        cin>>op;
        if (op==1){
            int x,y; cin>>x>>y;
            if (q[id[x]].size()<q[id[y]].size()){
                int prex=x,prey=y;
                x=id[x]; y=id[y];
                swap(id[prex],id[prey]);
                int tmp=q[x].size()-1,tmp1=q[y].size()-1;
                while (!q[x].empty()){
                    int u=q[x].front(); q[x].pop();
                    belong[u]=y;
                    v[u]=2ll*v[u]%mod;
                    v[u]=1ll*v[u]*f2[c2[x]]%mod*f3[c3[x]]%mod;
                    v[u]=1ll*v[u]*inv2[c2[y]]%mod*inv3[c3[y]]%mod;
                    v[u]=1ll*v[u]*inv3[tmp]%mod*f3[tmp1]%mod;
                    q[y].push(u);
                }
                c3[y]+=tmp;
            } else {
                x=id[x]; y=id[y];
                int tmp=q[y].size()-1,tmp1=q[x].size()-1;
                while (!q[y].empty()){
                    int u=q[y].front(); q[y].pop();
                    belong[u]=x;
                    v[u]=1ll*v[u]*inv2[1]%mod;
                    v[u]=1ll*v[u]*f2[c2[y]]%mod*f3[c3[y]]%mod;
                    v[u]=1ll*v[u]*inv2[c2[x]]%mod*inv3[c3[x]]%mod;
                    v[u]=1ll*v[u]*inv3[tmp]%mod*f3[tmp1]%mod;
                    q[x].push(u);
                }
                c2[x]++;
                c3[x]+=tmp;
            }
        } else {
            int x; cin>>x;
            cout<<1ll*f3[n-q[belong[x]].size()+c3[belong[x]]]*v[x]%mod*f2[c2[belong[x]]]%mod<<"\n";
        }
    }
    return 0;
}
