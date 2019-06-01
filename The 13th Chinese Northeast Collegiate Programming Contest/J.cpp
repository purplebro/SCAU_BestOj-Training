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

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int n,x,ans,T;
    cin>>T;
    while(T--) {
        cin>>n;
        cin>>x; ans=3*x;
        for(int i=1;i<n;i++){
            cin>>x;
            ans=max(ans,x+1);
        }
        if(ans&1) ++ans;
        cout<<ans<<"\n";
    }
    return 0;
}
