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
const int maxn = 5e3+10;
const int maxm = 1e6+10;
const int N = 2e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
namespace IO {
    const int MX = 4e7;
    char buf[MX];
    int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        for (;c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9');) c++;
        if (c >= sz)
            return false;
        bool flag = 0;
        if (buf[c] == '-') {
            flag = 1;
            c++;
        }
        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
            t = t * 10 + buf[c] - '0';
        if (flag)
            t = -t;
        return true;
    }
}
ll dist(pii a){
    return 1ll*a.X*a.X+1ll*a.Y*a.Y;
}
ll cross(pii a,pii b){
    return 1ll*a.X*b.Y-1ll*a.Y*b.X;
}
pii p[maxn];
int stk[maxn],top;
void Graham(int n){
    top=0;
    for (int i=0;i<n;i++){
        while (top>=2 && cross(pii(p[stk[top-1]].X-p[stk[top-2]].X,p[stk[top-1]].Y-p[stk[top-2]].Y),
                               pii(p[i].X-p[stk[top-2]].X,p[i].Y-p[stk[top-2]].Y))<=0) top--;
        stk[top++]=i;
    }
}
ll cal(int i,int j,int k){
    return abs(cross(p[stk[i]],p[stk[j]])+cross(p[stk[j]],p[stk[k]])+cross(p[stk[k]],p[stk[i]]));
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    IO::begin();
    int n; IO::read(n);
    for (int i=0;i<n;i++){
        IO::read(p[i].X);
        IO::read(p[i].Y);
    }
    sort(p,p+n);
    n=unique(p,p+n)-p;
    int dx,dy,k=-1;
    for (int i=0;i<n;i++){
        if (k==-1 || p[i].X<p[k].X || (p[i].X==p[k].X && p[i].Y<p[k].Y)) {
            k=i;
            dx=p[k].X;
            dy=p[k].Y;
        }
    }
    for (int i=0;i<n;i++){
        p[i].X-=dx; p[i].Y-=dy;
    }
    sort(p,p+n,[](const pii &l,const pii &r){
            return 1ll*l.X*r.Y>1ll*l.Y*r.X || 1ll*l.X*r.Y==1ll*l.Y*r.X && dist(l)<dist(r);
        });
    Graham(n);
    if (top<=2){
        cout<<setprecision(5)<<fixed<<0<<"\n";
    } else {
        ll ans=0;
        for (int i=0;i<top;i++) {
            int k=i+1;
            for (int j=i+1;j<top;j++){
                while (k+1<j && cal(i,j,k+1)>cal(i,j,k)) k++;
                if (k<j) ans=max(ans,cal(i,j,k));
            }
        }
        cout<<setprecision(5)<<fixed<<(double)ans*0.5<<"\n";
    }
    return 0;
}
