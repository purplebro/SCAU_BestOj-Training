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
const int maxn = 1e3+10;
const int maxm = 3e5+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
//namespace IO {
//    const int MX = 4e7;
//    char buf[MX];
//    int c, sz;
//    void begin() {
//        c = 0;
//        sz = fread(buf, 1, MX, stdin);
//    }
//    inline bool read(int &t) {
//        for (;c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9');) c++;
//        if (c >= sz)
//            return false;
//        bool flag = 0;
//        if (buf[c] == '-') {
//            flag = 1;
//            c++;
//        }
//        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
//            t = t * 10 + buf[c] - '0';
//        if (flag)
//            t = -t;
//        return true;
//    }
//}
pii p[maxn];
int a[maxn],b[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
    }
    ll ans,tmp;
    ans=0;
    for(int i=1;i<=n;i++) {
        tmp=0;
        for(int j=1;j<=n;j++) {
            p[j].X=b[j]*i-a[j];
            p[j].Y=j;
        }
        sort(p+1,p+1+n);
        for(int j=1;j<=i;j++) tmp+=a[p[j].Y];
        for(int j=i+1;j<=n;j++) tmp+=b[p[j].Y]*i;
        ans=max(ans,tmp);
    }
    cout<<ans;
    return 0;
}
