#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 1e3+10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9+7;
const double PI = acos(-1.);
char s[maxn][maxn];
int a[maxn],le[maxn],ri[maxn];
stack<int> stk;
void update(int &mx,int &mmx,int val){
    if (val<=mmx) return;
    if (val<=mx){
        mmx=val;
        return;
    }
    mmx=mx;
    mx=val;
}
int main() {
#ifdef LOCAL
    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    int mx=0,mmx=0;
    for (int i=0;i<n;i++) cin>>s[i];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (s[i][j]=='1') a[j]++; else a[j]=0;
            le[j]=j;
            ri[j]=m-1;
        }
//        for (int j=0;j<m;j++) cout<<a[j]<<" "; cout<<endl;
        while (!stk.empty()) stk.pop();
        for (int j=0;j<m;j++){
            while (!stk.empty() && a[stk.top()]>=a[j]){
                le[j]=le[stk.top()];
                ri[stk.top()]=j-1;
                stk.pop();
            }
            stk.push(j);
        }
        int _mx=0,_mmx=0;
        for (int j=0;j<m;j++){
            int x=ri[j]-le[j]+1,y=a[j];
            update(_mx,_mmx,x*y);
            update(_mx,_mmx,(x-1)*y);
            update(_mx,_mmx,x*(y-1));
        }
        update(mx,mmx,_mx);
        update(mx,mmx,_mmx);
    }
    cout<<mmx<<"\n";
    return 0;
}
