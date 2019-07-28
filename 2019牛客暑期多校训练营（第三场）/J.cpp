#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
#define mst(a, b) memset(a, b, sizeof(a))
#define X first
#define Y second
#define lowbit(x) (x&(-x))
const int maxn = 500000+10;
const int maxm = 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 998244353;
const double PI = acos(-1.);
const double eps = 1e-12;
gp_hash_table<ll,int> id;
int val[maxn],tot,idx[maxn],a[maxn],pre[maxn],nx[maxn];
char s[20];
int get_node(){
    ll H=0;
    int n=strlen(s);
    for (int i=0;i<n;i++){
        int x=s[i]-'0'+1;
        H=H*11+x;
    }
    if (!id[H]) id[H]=tot++;
    return id[H];
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int T; scanf("%d",&T);
    while (T--){
        int n,m; scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) pre[i]=nx[i]=idx[i]=-1;
        id.clear();
        tot=1;
        int sz=0,top=-1,tail=-1;
        int op,v,node;
        for (int i=0;i<n;i++){
            scanf("%d%s%d",&op,s,&v);
            node=get_node();
            if (op==0){
                if (idx[node]==-1){
                    idx[node]=i;
                    val[node]=v;
                    a[i]=node;
                    if (sz==m) {
                        idx[a[top]]=-1;
                        if (m>1){
                            top=nx[top];
                            pre[top]=-1;
                        }
                        sz--;
                    }
                    sz++;
                    if (sz==1){
                        top=tail=i;
                        nx[i]=pre[i]=-1;
                    } else {
                        nx[tail]=i;
                        nx[i]=-1;
                        pre[i]=tail;
                        tail=i;
                    }
                } else {
                    int cur=idx[node];
                    idx[node]=i;
                    a[i]=node;
                    if (sz==1){
                        top=tail=i;
                        nx[i]=pre[i]=-1;
                    } else {
                        if (cur==top){
                            top=nx[top];
                            pre[top]=-1;
                        } else if (cur==tail) {
                            tail=pre[tail];
                            nx[tail]=-1;
                        } else {
                            pre[nx[cur]]=pre[cur];
                            nx[pre[cur]]=nx[cur];
                        }
                        pre[i]=tail;
                        nx[tail]=i;
                        nx[i]=-1;
                        tail=i;
                    }
                }
                printf("%d\n",val[node]);
            } else {
                if (idx[node]==-1){
                    puts("Invalid");
                } else {
                    int cur=idx[node];
                    if (v==1){
                        if (cur==tail) puts("Invalid"); else
                            printf("%d\n",val[a[nx[cur]]]);
                    } else if (v==-1){
                        if (cur==top) puts("Invalid"); else {
                            printf("%d\n",val[a[pre[cur]]]);
                        }
                    } else {
                        printf("%d\n",val[a[cur]]);
                    }
                }
            }
        }
    }
    return 0;
}
