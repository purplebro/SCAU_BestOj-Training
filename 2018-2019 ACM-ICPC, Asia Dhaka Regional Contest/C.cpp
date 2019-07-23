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
const int maxn = 5e3+10;
const int maxm = 1e6+10;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e7+7;

int prime[M], tot;
int minPrime[N];
bool vis[N];

inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            minPrime[i] = i;
        }
        for (int j = 0; j < tot && i * prime[j] < N; j++) {
            minPrime[i] = prime[j];
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int n;
    while (cin>>n && n){
        int ans=1;
        for (int i=0;i<tot && prime[i]<=n;i++){
            int cnt=0,x=n;
            for (;x;x/=prime[i]){
                cnt+=x/prime[i];
            }
            int res=(1ll*(cnt+2)*(cnt+1)/2)%mod;
            ans=1ll*ans*res%mod;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
