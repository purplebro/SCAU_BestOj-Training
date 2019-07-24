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
const int maxm = 4e6+10;

const int N = 3e5 + 10;
const int M = 2e4 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int all;
int son[N][26];
int fail[N];
int siz[N];
int len[N];
int text[N];
int last;
int tot;
int head[N];
int to[N];
int nxt[N];
int cnt;
char s[N];
int res[N];
bool vis[N];

inline int newNode(int l) {
    for (int i = 0; i < 26; i++)
        son[tot][i] = 0;
    siz[tot] = 0;
    len[tot] = l;
    return tot++;
}
inline void addEdge(int u, int v) {
    nxt[++cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}
void init() {
    cnt = last = tot = all = 0;
    newNode(0), newNode(-1);
    text[0] = -1, fail[0] = 1;
}
int getFail(int x) {
    for (;text[all - len[x] - 1] != text[all];)
        x = fail[x];
    return x;
}
void extend(int w) {
    text[++all] = w;
    int x = getFail(last);
    if (!son[x][w]) {
        int y = newNode(len[x] + 2);
        fail[y] = son[getFail(fail[x])][w];
        addEdge(fail[y], y);
//        cout << fail[y] << " " << y << "\n";
        son[x][w] = y;
    }
    siz[last = son[x][w]]++;
}
void cont() {
    for (int i = tot - 1; ~i; i--)
        siz[fail[i]] += siz[i];
}
void dfs(int u) {
    vis[len[u]] = true;

    int p = len[u] / 2 + (len[u] % 2);
//    cout << p << "\n";
    if (vis[p])
        res[len[u]] += siz[u];

    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        dfs(v);
    }

    vis[len[u]] = false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (;cin >> s + 1;) {
        init();
        int leng = strlen(s + 1);
        for (int i = 1; i <= leng; i++)
            extend(s[i] - 'a');
        cont();
        dfs(0);
        for (int i = 1; i <= leng; i++) {
            cout << res[i] << " \n"[i == leng];
            res[i] = 0;
        }
        for (int i = 0; i <= tot; i++)
            head[i] = 0;
    }

    return 0;
}
