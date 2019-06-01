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
const int maxn = 200000+10;
const int maxm = 200000+10;
const int N = 1e5 + 10;
pii x[maxn<<1],y[maxn<<1];
int n;
ll solve(pii *a){
    int m=(n<<1);
    sort(a,a+m);
    ll res=0;
    for (int i=0;i<m;i++){
        if (a[i].Y) continue;
        res+=a[i].X-a[0].X;
    }
    ll ans=res;
    int cntL=1,cntR=n;
    for (int i=1;i<m;i++){
        int d=a[i].X-a[i-1].X;
        res+=1ll*d*cntL;
        res-=1ll*d*cntR;
        ans=min(ans,res);
        if (a[i].Y){
            cntL++;
        } else {
            cntR--;
        }
    }
    return ans;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int T; cin>>T;
    while (T--){
        cin>>n;
        for (int i=0;i<n;i++){
            int a,b,c,d; cin>>a>>b>>c>>d;
            x[i<<1]=pii(a,0);
            x[i<<1|1]=pii(c,1);
            y[i<<1]=pii(b,0);
            y[i<<1|1]=pii(d,1);
        }
        ll ans=solve(x)+solve(y);
        cout<<ans<<"\n";
    }
    return 0;
}
