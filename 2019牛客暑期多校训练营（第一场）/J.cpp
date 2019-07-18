#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 100+10;
const int maxm = 10000+10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x,y;
    int a,b;
    while (cin>>x>>a>>y>>b){
        __int128 t1=x,t2=y;
        t1=t1*b;
        t2=t2*a;
        if (t1==t2) puts("="); else
            if (t1<t2) puts("<"); else puts(">");
    }
    return 0;
}
