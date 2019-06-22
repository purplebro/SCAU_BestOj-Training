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
const int maxn = 2e5+10;
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

//const int dir[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
//bool vis[100][100];
pii st,en;
int n,m;
//bool check(int x,int y){
//    return 1<=x && x<=n && 1<=y && y<=m;
//}
//void dfs(int x,int y){
//    for (int i=0;i<8;i++){
//        int dx=x+dir[i][0],dy=y+dir[i][1];
//        if (check(dx,dy) && !vis[dx][dy]){
//            vis[dx][dy]=true;
//            dfs(dx,dy);
//        }
//    }
//}
int a[2][2]={1,2,3,4},b[2][2]={3,4,1,2};
int hehe(int x,int y){
    x--; y--;
    int k=y/2;
    if (k&1){
        return a[x][y%2];
    } else {
        return b[x][y%2];
    }
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    IO::begin();
    cin>>n>>m;
    cin>>st.X>>st.Y>>en.X>>en.Y;
    if (n>m){
        swap(n,m);
        swap(st.X,st.Y);
        swap(en.X,en.Y);
    }
    if (((st.X&1) == (st.Y&1) && (en.X&1) == (en.Y&1)) || ((st.X&1) != (st.Y&1) && (en.X&1) != (en.Y&1))){
        cout<<"No\n";
        return 0;
    }
    if (n==3 && m==3 && (st==pii(2,2) || en==pii(2,2))){
        cout<<"No\n";
        return 0;
    }
    if (n==2){
        if (hehe(st.X,st.Y)==hehe(en.X,en.Y)){
            cout<<"Yes\n";
        } else cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
//    n=3; m=7;
//    vis[1][1]=true;
//    dfs(1,1);
//    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++){
//        if (!vis[i][j]) cout<<i<<" "<<j<<endl;
//    }
    return 0;
}
