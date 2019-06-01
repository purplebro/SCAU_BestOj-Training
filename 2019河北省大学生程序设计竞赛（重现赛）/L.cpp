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
const int N = 1e7 + 10;
const int maxn = 1e5 + 10;
const int maxm = 2.5e7 + 10;
const int inf=0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
const int st=(1<<20)-1;
const ll mod = 1e9+7;
const double eps = 1e-8;

bool vis[N];
int G[55][55];
bool level[10];
int down;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<pii, pii> > Q;
int n;

int bfs() {
    for (;!Q.empty();) {
        pair<pii, pii> t = Q.front();
        Q.pop();
        int lev = t.Y.Y;
        if (!level[lev]) {
            level[lev] = true;
            for (int i = down == 1 ? 0 : down; i <= down * 10 - 1; i++) if (!vis[i])
                return i;
            down *= 10;
        }
        for (int i = 0; i < 4; i++) {
            int toX = t.X.X + dx[i];
            int toY = t.X.Y + dy[i];
            if (toX >= 1 && toX <= n && toY >= 1 && toY <= n) {
                vis[t.Y.X * 10 + G[toX][toY]] = true;
                Q.push(make_pair(pii(toX, toY), pii(t.Y.X * 10 + G[toX][toY], t.Y.Y + 1)));
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
            vis[G[i][j]] = true;
            Q.push(make_pair(pii(i, j), pii(G[i][j], 1)));
        }
    }

    down = 1;

    printf("%d\n", bfs());

    return 0;
}
