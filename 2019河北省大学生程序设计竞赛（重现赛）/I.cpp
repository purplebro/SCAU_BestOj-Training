#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout << #a": " << a << endl;
#define mst(a, b) memset(a, b, sizeof(a))
#define lc rt << 1
#define rc rt << 1 | 1
#define X first
#define Y second
inline int lowbit(int x) { return x & -x; }
typedef long long LL;
typedef pair<LL, LL> pll;
const int N = 5e4 + 10;
const int M = 2e6 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 16711680;


struct Node {
    int x, y, id, t, val, p;
}used[N << 4];
int x[N];
int y[N];
int a[N];
int b[N];
LL sum[M];
LL cnt[M];
LL ans[N];
int n, q, c;

inline void update(int pos, int val) {
    for (; pos < M; pos += lowbit(pos))
        sum[pos] += val, cnt[pos]++;
}
inline pll query(int pos) {
    pll res(0, 0);
    for (; pos; pos -= lowbit(pos))
        res.X += sum[pos], res.Y += cnt[pos];
    return res;
}
inline void clr(int pos) {
    for (; pos < M; pos += lowbit(pos))
        sum[pos] = cnt[pos] = 0;
}
bool cmp1(Node a, Node b) {
    return a.x == b.x ? abs(a.t) < abs(b.t) : a.x < b.x;
}
bool cmp2(Node a, Node b) {
    return a.y == b.y ? abs(a.t) < abs(b.t) : a.y < b.y;
}
void cdq(int L, int R) {
    if (L >= R)
        return ;
    int mid = L + R >> 1;
    cdq(L, mid);
    cdq(mid + 1, R);
    int pos = L;
    for (int i = mid + 1; i <= R; i++) if (used[i].t) {
        for (; pos <= mid && used[pos].y <= used[i].y; pos++) if (!used[pos].t)
            update(used[pos].p, used[pos].val);
        pll a = query(used[i].p), b = query(M - 1);
        b.X -= a.X;
        b.Y -= a.Y;
        ans[used[i].id] += (a.X + a.Y * used[i].val) * used[i].t;
        ans[used[i].id] += (b.X - b.Y * c + b.Y * used[i].val) * used[i].t;
    }
    for (int i = L; i <= mid; i++) if (!used[i].t)
        clr(used[i].p);
    sort(used + L, used + R + 1, cmp2);
}

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d%d", &n, &q, &c);
    c++;

    int tot = 0;

    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &x[i], &y[i], &a[i]);

    for (int i = 1; i <= n; i++)
        b[i] = a[i];

    sort(b + 1, b + 1 + n);
    int k = unique(b + 1, b + 1 + n) - b - 1;

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + 1 + k, a[i]) - b;
        used[++tot] = (Node){x[i], y[i], 0, 0, a[i], pos};
    }

    for (int i = 1; i <= q; i++) {
        int x[2];
        int y[2];
        int t;
        scanf("%d%d%d%d%d", &t, &x[0], &y[0], &x[1], &y[1]);
        int pos = lower_bound(b + 1, b + 1 + k, c - t) - b;

        used[++tot] = (Node){x[0] - 1, y[0] - 1, i, 1, t, pos - 1};
        used[++tot] = (Node){x[0] - 1, y[1], i, -1, t, pos - 1};
        used[++tot] = (Node){x[1], y[0] - 1, i, -1, t, pos - 1};
        used[++tot] = (Node){x[1], y[1], i, 1, t, pos - 1};
    }

    sort(used + 1, used + 1 + tot, cmp1);
    cdq(1, tot);

    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
