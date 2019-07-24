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
const int maxn = 1e6+10;
const int maxm = 1e6+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e6+3;
int a[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    a[0]=1;
    for (int i=1;i<=mod;i++) a[i]=1ll*a[i-1]*i%mod;
    int n;
    while (cin>>n){
        if (n<mod) cout<<a[n]<<"\n"; else
            cout<<0<<"\n";
    }
    return 0;
}
