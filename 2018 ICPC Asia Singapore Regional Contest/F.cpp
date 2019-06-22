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
const int maxn = 4e5+10;
const int maxm = 1e6+10;
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
int p[maxn],to[maxn],a[maxn];
int seg[maxn<<2];
void pushup(int o){
    seg[o]=max(seg[o<<1],seg[o<<1|1]);
}
void build(int o,int L,int R){
    if (L==R){
        seg[o]=to[L];
        return;
    }
    int M=L+(R-L)/2;
    build(o<<1,L,M);
    build(o<<1|1,M+1,R);
    pushup(o);
}
int query(int o,int L,int R,int ql,int qr){
    if (ql<=L && R<=qr){
        return seg[o];
    }
    int M=L+(R-L)/2,res=-inf;
    if (ql<=M) res=max(res,query(o<<1,L,M,ql,qr));
    if (qr>M) res=max(res,query(o<<1|1,M+1,R,ql,qr));
    return res;
}
bool can[maxn];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    IO::begin();
    mst(to,-1);
    int n; cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        if (p[a[i]]){
            to[p[a[i]]]=i;
        }
        p[a[i]]=i;
    }
    build(1,1,n);
    int mn=inf;
    for (int i=1;i<=n;i++){
        if (~to[i] && to[i]-i>1){
            int res=query(1,1,n,i+1,to[i]-1);
            if (res>to[i]){
                can[i]=true;
                mn=min(mn,a[i]);
            }
        }
    }
    if (mn==inf) {
        cout<<-1<<"\n";
        return 0;
    }
    int _mn=inf;
    for (int i=1;i<=n;i++){
        if (can[i] && a[i]==mn){
            for (int j=i+1;j<to[i];j++){
                if (to[j]>to[i]){
                    _mn=min(_mn,a[j]);
                }
            }
        }
    }
    cout<<mn<<" "<<_mn<<"\n";
    return 0;
}
