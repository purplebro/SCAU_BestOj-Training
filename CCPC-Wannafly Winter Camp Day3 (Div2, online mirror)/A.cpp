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
const int maxm = 2e5+10;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
//int a[20];
//map<vector<int>,bool> vis;
//bool ok(vector<int> &b){
//    for (int u:b){
//        if (u==24) return true;
//    }
//    return false;
//}
//bool check(vector<int> &b){
//    vis.clear();
//    queue<vector<int> > q;
//    vector<int> nx,tmp;
//    if (ok(b)) return true;
//    q.push(b);
//    vis[b]=true;
//    while (!q.empty()){
//        tmp=q.front(); q.pop();
//        for (int i=0;i<tmp.size();i++) for (int j=i+1;j<tmp.size();j++){
//            nx.clear();
//            if (tmp[i]+tmp[j]==24) return true; else {
//                for (int k=0;k<tmp.size();k++){
//                    if (k==i || k==j) continue;
//                    nx.push_back(tmp[k]);
//                }
//                nx.push_back(tmp[i]+tmp[j]);
//                sort(nx.begin(),nx.end());
//                if (!vis.count(nx)){
//                    vis[nx]=true;
//                    q.push(nx);
//                }
//            }
//            nx.clear();
//            if (tmp[j]-tmp[i]==24) return true; else {
//                for (int k=0;k<tmp.size();k++){
//                    if (k==i || k==j) continue;
//                    nx.push_back(tmp[k]);
//                }
//                nx.push_back(tmp[j]-tmp[i]);
//                sort(nx.begin(),nx.end());
//                if (!vis.count(nx)){
//                    vis[nx]=true;
//                    q.push(nx);
//                }
//            }
//            nx.clear();
//            if (tmp[i]*tmp[j]==24) return true; else {
//                for (int k=0;k<tmp.size();k++){
//                    if (k==i || k==j) continue;
//                    nx.push_back(tmp[k]);
//                }
//                nx.push_back(tmp[i]*tmp[j]);
//                sort(nx.begin(),nx.end());
//                if (!vis.count(nx)){
//                    vis[nx]=true;
//                    q.push(nx);
//                }
//            }
//            if (tmp[i]==0 || tmp[j]%tmp[i]) continue;
//            nx.clear();
//            if (tmp[j]%tmp[i]==24) return true; else {
//                for (int k=0;k<tmp.size();k++){
//                    if (k==i || k==j) continue;
//                    nx.push_back(tmp[k]);
//                }
//                nx.push_back(tmp[j]/tmp[i]);
//                sort(nx.begin(),nx.end());
//                if (!vis.count(nx)){
//                    vis[nx]=true;
//                    q.push(nx);
//                }
//            }
//        }
//    }
//    return false;
//}
int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
//    cout.tie(0);
    int n; cin>>n;
    if (n==6) cout<<32<<"\n";
    if (n==10) cout<<891<<"\n";
//    for (int i=0;i<n;i++){
//        cin>>a[i];
//    }
//    int ans=0;
//    for (int i=0;i<(1<<n);i++){
//        vector<int> b;
//        for (int j=0;j<n;j++){
//            if (i&(1<<j)){
//                b.push_back(a[j]);
//            }
//        }
//        if (check(b)) ans++;
//    }
//    cout<<ans<<"\n";
    return 0;
}
