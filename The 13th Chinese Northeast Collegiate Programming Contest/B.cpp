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
const int N = 1e5 + 10;

struct Node {
    int a, l;
    inline bool operator < (const Node &t) const {
        return l>t.l;
    }
};
priority_queue<Node> Q;
vector<int> a[maxn];
pii l[maxn];

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int T;

    scanf("%d", &T);

    for (;T--;) {
        int n, m;

        scanf("%d%d", &n, &m);

        for (int i = 1; i <= m; i++)
            scanf("%d", &l[i].X),l[i].Y=i,a[i].clear();

        for (int i = 1; i <= n; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            a[y].emplace_back(-x);
        }

        sort(l+1,l+1+m);
        for(int i=1;i<=m;i++) {
            sort(a[i].begin(),a[i].end());
        }
        int x;
        ll t1=0,t2;
        ll ans1=0,ans2=0;
        for(int i=1;i<=m;i++) {
            x=l[i].X;
            int y=l[i].Y;
            if(a[y].size()>=x)
                for(int j=0,top=a[y].size();j<top;j++) {
                    Q.push({-a[y][j],j});
    //                cout<<-a[i][j]<<' '<<j<<endl;
                }
            while(!Q.empty()&&Q.top().l<x) {
                t1+=Q.top().a;
                Q.pop();
            }
            t2=x;
            if(ans2*t1>=ans1*t2){
                ans1=t1;
                ans2=t2;
            }
        }
        for(int i=x+1;!Q.empty();i++) {
            while(!Q.empty()&&Q.top().l<i) {
                t1+=Q.top().a;
                Q.pop();
            }
            t2=i;
            if(ans2*t1>=ans1*t2){
                ans1=t1;
                ans2=t2;
            }
        }
        ll tmp=__gcd(ans1,ans2);
        printf("%lld/%lld\n",ans1/tmp,ans2/tmp);
    }

    return 0;
}
