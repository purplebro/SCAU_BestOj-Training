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
const int N = 1e6 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
int get(int h,int m,int s){
    return h*60*60+m*60+s;
}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n;
    while (~scanf("%d\n",&n) && n){
        char op;
        int h1,m1,s1,h2,m2,s2;
        int cnt=0;
        for (int i=0;i<n;i++){
            scanf("%c:%d:%d:%d:%d:%d:%d\n",&op,&h1,&m1,&s1,&h2,&m2,&s2);
//            cout<<op<<" "<<h1<<" "<<m1<<" "<<s1<<" "<<h2<<" "<<m2<<" "<<s2<<endl;
            int st=get(h1,m1,s1),en=get(h2,m2,s2);
            if (op=='D'){
                int t=en-max(get(8,30,0),st);
                if (st>get(9,30,0) || t<8*60*60) cnt++;
            } else {
                int t=en-max(get(8,30,0),st);
                if (st>get(12,30,0) || t<9*60*60) cnt++;
            }
        }
        if (cnt==0) printf("All OK\n"); else
        if (cnt>3) printf("Issue Show Cause Letter\n"); else
            printf("%d Point(s) Deducted\n",cnt);
    }

    return 0;
}
