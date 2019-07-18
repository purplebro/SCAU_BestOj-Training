#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 100000+10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int a[maxn],b[maxn],lea[maxn],leb[maxn];
stack<int> stk;
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin>>n){
        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++){
            cin>>a[i];
            lea[i]=i;
            while (!stk.empty() && a[stk.top()]>a[i]){
                lea[i]=lea[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++){
            cin>>b[i];
            leb[i]=i;
            while (!stk.empty() && b[stk.top()]>b[i]){
                leb[i]=leb[stk.top()];
                stk.pop();
            }
            stk.push(i);
        }
        int ans=n;
        for (int i=0;i<n;i++){
            if (lea[i]!=leb[i]){
                ans=i;
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
