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
const int maxn = 5e5+10;
const int maxm = 1e6+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
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
struct edge{
    int to,n;
}e[maxm];
int head[maxn],tot;
inline void add(int x,int y){
    e[++tot].to=y;
    e[tot].n=head[x];
    head[x]=tot;
}
int f[maxn];
bool t;
inline void dfs(int u) {
    for(int i=head[u];i;i=e[i].n) {
        int v=e[i].to;
        if(f[v]==-1) f[v]=f[u]^1,dfs(v);
        else if(f[u]==f[v]) t=true;
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    int n,m;
    int x,y;
    int cnt=0;
    cin>>n>>m;
    for(;m--;) {
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++) {
        if(f[i]==-1) {
            cnt++;
            f[i]=0;
            dfs(i);
        }
    }
    if(t) cout<<cnt-1;
    else cout<<cnt;
    return 0;
}
