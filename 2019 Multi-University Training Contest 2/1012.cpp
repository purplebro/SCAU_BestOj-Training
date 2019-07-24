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
const int mod = 1e9+7;

int a[maxn],tot[maxn],num[maxn],cnt;
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,c,k;
    for (;cin>>n>>c>>k;) {
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            tot[a[i]]++;
        }
        int i,j,p;
        int ans=0;
        for(i=1;i<=n;tot[a[i++]]--) {
            if(tot[a[i]]<k) {
                continue;
            }
            p=cnt=0;
            for(j=i;j<=n;j++) {
                if(tot[a[j]]<k) break;
                num[a[j]]++;
                if(num[a[j]]==1) {
                    cnt++;
                }
                if(num[a[j]]==k) cnt--;
                if(!cnt) {
                    p=j;
                }
            }
            for(j--;j>=i;j--) num[a[j]]--;
            if(p) {
                ans=max(ans,p-i+1);
                for(;i<p;i++) {
                    tot[a[i]]--;
                }
                i=p;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
