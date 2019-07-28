#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
#define debug(a) cout << #a": " << a << endl;
const int maxn = 1000+10;
const int maxm = 10;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
int cnt[5];
vector<int> pos[5];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while (T--){
        ll n; cin>>n;
        pos[1].clear();
        pos[2].clear();
        cnt[1]=cnt[2]=0;
        int k=1;
        for (int i=0;i<60;i++){
            if (n&(1ll<<i)){
                cnt[k]++;
                pos[k].push_back(i);
            }
            k=3-k;
        }
        int hehe1=cnt[1],hehe2=cnt[2];
        int c1,c2,tmp=min(cnt[1],cnt[2]);
        c1=c2=tmp;
        cnt[1]-=tmp; cnt[2]-=tmp;
        c1+=(cnt[1]/3)*3;
        c2+=(cnt[2]/3)*3;
        cnt[1]%=3; cnt[2]%=3;
        if (cnt[1]==0 && cnt[2]==0){
            cout<<1;
        } else cout<<2;
        ll res=0,hehe=0;
        for (int i=0;i<c1;i++) res|=(1ll<<pos[1][i]);
        for (int i=0;i<c2;i++) res|=(1ll<<pos[2][i]);
        cout<<" "<<res;
        res=0;
        if (cnt[1]){
            if (cnt[1]==1){
                res|=(1ll<<pos[1][c1]);
                if (hehe2) res|=(1ll<<pos[2][0]); else {
                    res|=(1ll<<pos[1][0]);
                    res|=(1ll<<pos[1][1]);
                }
            } else {
                for (int i=0;i<3;i++) res|=(1ll<<pos[1][pos[1].size()-i-1]);
            }
            cout<<" "<<res;
        } else if (cnt[2]){
            if (cnt[2]==1){
                res|=(1ll<<pos[2][c2]);
                if (hehe1) res|=(1ll<<pos[1][0]); else {
                    res|=(1ll<<pos[2][0]);
                    res|=(1ll<<pos[2][1]);
                }
            } else {
                for (int i=0;i<3;i++) res|=(1ll<<pos[2][pos[2].size()-i-1]);
            }
            cout<<" "<<res;
        }
        cout<<"\n";
    }
    return 0;
}
