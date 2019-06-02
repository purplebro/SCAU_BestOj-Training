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
int ans[maxn],a[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int n; cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int x=1;
    for (int i=1;i<=n;i++){
        int j=i;
        while (j+1<=n && a[j]<a[j+1]) j++;
        ans[a[i]]=x++;
        i=j;
    }
    for (int i=1;i<=n;i++){
        if (ans[i]==0) ans[i]=x++;
        if (i>1) cout<<" ";
        cout<<ans[i];
    }
    cout<<"\n";
    return 0;
}
