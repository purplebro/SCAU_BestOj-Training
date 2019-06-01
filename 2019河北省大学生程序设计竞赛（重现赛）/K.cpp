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
const int N = 2e5 + 10;
const int maxn = 1e6 + 10;
const int maxm = 2.5e7 + 10;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const ll mod = 1e9+7;
const double eps = 1e-8;

vector<string> ve;
map<string, int> mp;

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        int t;

        cin >> s >> t;

        mp[s] = t;
        ve.emplace_back(s);
    }

    bool flag = true;

    for (int i = 1; i <= m; i++) {
        int k;

        cin >> k;

        for (int j = 1; j <= k; j++) {
            string s;
            int t;

            cin >> s >> t;

            if (mp[s] >= t)
                mp[s] -= t;
            else
                flag = false;
        }
    }

    if (!flag)
        cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";

        for (string it : ve) if (mp[it])
            cout << it << " " << mp[it] << "\n";
    }

    return 0;
}
