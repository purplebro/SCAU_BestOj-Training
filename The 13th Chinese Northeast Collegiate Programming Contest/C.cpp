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
const int maxn = 100000+10;
map<double,int> cnt;
map<pair<double,double>,int> cc;
int x[maxn],y[maxn],x2[maxn],y2[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        cnt.clear();
        cc.clear();
        for (int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>x2[i]>>y2[i];
            double k=1e50,d=x[i];
            if (x[i]!=x2[i]){
                k=(double)(y[i]-y2[i])/(double)(x[i]-x2[i]);
                d=((double)x[i]*y2[i]-(double)x2[i]*y[i])/(double)(x[i]-x2[i]);
            }
            cnt[k]++;
            cc[make_pair(k,d)]++;
        }
        ll ans=0;
        for (int i=0;i<n;i++){
            double k=1e50,d=x[i];
            if (x[i]!=x2[i]){
                k=(double)(y[i]-y2[i])/(double)(x[i]-x2[i]);
                d=((double)x[i]*y2[i]-(double)x2[i]*y[i])/(double)(x[i]-x2[i]);
            }
            ans+=(n-cnt[k])+(cc[make_pair(k,d)]-1);
        }
        cout<<ans/2<<"\n";
    }
    return 0;
}
