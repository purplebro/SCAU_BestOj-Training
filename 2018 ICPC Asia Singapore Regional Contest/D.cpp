#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) ((x)&(-x))
#define X first
#define Y second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 500000+10;
const int maxm = 4000+10;
const int mod = 998244353;
const double eps = 1e-9;
int a[maxn];
int p[50];
int n,k;
bool check(int x){
    for (int i=0;i<=30;i++){
        if (~p[i] && x&(1<<i)){
            int cnt=0,s=0;
            for (int j=0;j<n && cnt<k;j++){
                s|=a[(p[i]+j)%n];
                if ((s&x)==x){
                    s=0;
                    cnt++;
                }
            }
            if (cnt>=k) return true;
        }
    }
    return false;
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    mst(p,-1);
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
        for (int j=0;j<=30;j++){
            if (a[i]&(1<<j)) {
                p[j]=i;
            }
        }
    }
    int ans=0;
    for (int i=30;i>=0;i--){
        if (check(ans|(1<<i))) ans|=(1<<i);
    }
    cout<<ans<<"\n";
    return 0;
}
