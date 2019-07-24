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
const int maxm = 4e6+10;
const int N = 3e5 + 10;
const int M = 2e4 + 10;
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
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin>>n){
        if (n==1) {
            cout<<0<<"\n";
            continue;
        }
        int x=(3+2*n-1)*(n-1)/2;
        cout<<1ll*x*qpow(9,mod-2)%mod<<"\n";
    }
    return 0;
}
