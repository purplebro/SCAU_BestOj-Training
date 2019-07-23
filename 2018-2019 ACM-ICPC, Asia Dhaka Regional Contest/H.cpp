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
const int maxn = 205;
const int maxm = 4e4+10;
const int N = 1e4 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 78294349;

int nex[maxm];
char s[maxn][maxn];
int a[maxn][maxn];
bool vis[maxm];
int has[maxm];
inline int dfs(int u) {
    vis[u]=true;
    if(!vis[nex[u]]) return 1+dfs(nex[u]);
    return 1;
}
inline int q_pow(int base, int b) {
    int res = 1;
    for (; b; b >>= 1, base = 1LL * base * base % mod) if (b & 1)
        res = 1LL * base * res % mod;
    return res;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T,n,m;
    cin>>T;
//    T=1;
//    srand(time(0));
    for(int k=1;k<=T;k++) {
        cout<<"Case "<<k<<": ";
        cin>>n>>m;
//        n=200; m=200;
//        int pre=0;
        for(int i=1;i<=n;i++) {
            cin>>(s[i]+1);
//            int hehe=rand()%6;
//            for (int j=1;j<=pre+hehe && j<=m;j++) s[i][j]='#';
//            pre=min(m,pre+hehe);
        }
        int cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                a[i][j]=0;
                if(s[i][j]=='#') {
                    a[i][j]=++cnt;
                }
            }
        }
        for(int i=1;i<=n;i++) {
            int tot=m;
            for(int j=m;j;j--) {
                if(a[i][j]) {
                    a[i][tot--]=a[i][j];
                }
            }
            for(int j=1;j<=tot;j++) a[i][j]=0;
        }
        for(int j=1;j<=m;j++) {
            int tot=1;
            for(int i=1;i<=n;i++) {
                if(a[i][j]) {
                    a[tot++][j]=a[i][j];
                }
            }
            for(int i=n;i>=tot;i--) a[i][j]=0;
        }
        for(int i=1;i<=n;i++) {
            int tot=1;
            for(int j=1;j<=m;j++) {
                if(a[i][j]) {
                    a[i][tot++]=a[i][j];
                }
            }
            for(int j=m;j>=tot;j--) a[i][j]=0;
        }
        for(int j=1;j<=m;j++) {
            int tot=n;
            for(int i=n;i;i--) {
                if(a[i][j]) {
                    a[tot--][j]=a[i][j];
                }
            }
            for(int i=1;i<=tot;i++) a[i][j]=0;
        }
        cnt=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(a[i][j]) {
                    nex[a[i][j]]=++cnt;
                }
            }
        }
        for(int i=1;i<=cnt;i++) vis[i]=false;
        ll ans=1;
        for(int i=1;i<=cnt;i++) {
            if(!vis[i]) {
                ll tmp=dfs(i);
                for (int j = 2; j * j <= tmp; j++) if (tmp % j == 0) {
                    int cnt = 0;
                    for (; tmp % j == 0;) {
                        tmp /= j;
                        cnt++;
                    }
                    has[j] = max(cnt, has[j]);
                }
                if (tmp != 1)
                    has[tmp] = max(has[tmp], 1);
            }
        }

        for (int i = 2; i < maxm; i++) if (has[i])
            ans = ans * q_pow(i, has[i]) % mod;

        cout << ans << "\n";

        mst(has, 0);
    }
    return 0;
}
