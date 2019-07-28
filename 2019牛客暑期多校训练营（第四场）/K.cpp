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
const int maxn = 100000+10;
const int maxm = 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;

char s[maxn];
int cnt[maxn][3];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    int n=strlen(s+1);
    cnt[0][0]=1;
    ll ans=0;
    int sum=0;
    for (int i=1;i<=n;i++){
        sum+=s[i]-'0';
        sum%=3;
        if (i>=3){
            if (s[i]=='0' && s[i-1]=='0') ans+=cnt[i-3][sum];
        }
        if (i>=2 && s[i-1]=='0' && s[i]=='0') ans++;
        if (s[i]=='0') ans++;
        for (int j=0;j<3;j++) cnt[i][j]=cnt[i-1][j];
        cnt[i][sum]++;
    }
    cout<<ans<<"\n";
    return 0;
}
