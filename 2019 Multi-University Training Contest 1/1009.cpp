#include <bits/stdc++.h>
using namespace std;
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
const int maxn = 1e5+10;
const int maxm = 1e5+10;
const int inf = 0x3f3f3f3f ;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 1e9+7;
const double PI = acos(-1.);
const double eps = 1e-12;

char s[maxn],ans[maxn];
int L[30],R[30],pos[30],cnt[30];
int nx[maxn][26],has[maxn][26];
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    while (cin>>(s+1)>>k){
        int n=strlen(s+1);
        for (int i=0;i<26;i++) cin>>L[i]>>R[i];
        mst(pos,-1);
        mst(cnt,0);
        for (int i=n;i>=0;i--){
            for (int j=0;j<26;j++){
                nx[i][j]=pos[j];
                has[i][j]=cnt[j];
            }
            if (i){
                pos[s[i]-'a']=i;
                cnt[s[i]-'a']++;
            }
        }
        for (int i=0;i<=k;i++) ans[i]=0;
        int cur=0;
        bool ff=true;
        for (int i=0;i<k;i++){
            for (int j=0;j<26;j++){
                int p=nx[cur][j];
                if (p==-1 || !R[j]) continue;

                int ll=L[j],rr=R[j];
                L[j]=max(0,L[j]-1);
                R[j]=max(0,R[j]-1);
                int sumL=0,sumR=0;
                bool flag=true;
                for (int x=0;x<26;x++){
                    if (has[p][x]<L[x]){
                        flag=false;
                        break;
                    }
                    sumL+=L[x];
                    sumR+=min(has[p][x],R[x]);
                }

                if (flag && sumL<=k-i-1 && sumR>=k-i-1){
                    ans[i]='a'+j;
                    cur=p;
                    break;
                }
                L[j]=ll;
                R[j]=rr;
            }

            if (!ans[i]){
                ff=false;
                break;
            }
        }

        if (!ff) cout<<-1<<"\n"; else cout<<ans<<"\n";
    }
    return 0;
}
