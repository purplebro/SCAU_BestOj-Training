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
const int maxm = 2e5+10;
const int N = 5000 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int f[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n,ans=0;
    int x,y;
    cin>>n;
    while(n--) {
        cin>>x>>y;
        f[x]++; f[y+1]--;
    }
    for(int i=1;i<=365;i++) {
        f[i]+=f[i-1];
        if(f[i]) ans++;
    }
    cout<<ans;
    return 0;
}
