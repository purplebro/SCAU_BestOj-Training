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
#define lc rt<<1
#define rc rt<<1|1
#define lowbit(x) ((x)&(-(x)))
#define ALL(x) begin(), end()
const int maxn = 1e5+10;
const int N = 1e5 + 10;

int n, m;
int a[N];
int b[N];
LL bits[N];
LL tree[N << 2];

inline void update(int pos, int val) {
    for (; pos <= n; pos += lowbit(pos))
        bits[pos] += val;
}
inline LL query(int pos) {
    LL res = 0;
    for (; pos; pos -= lowbit(pos))
        res += bits[pos];
    return res;
}
inline void pushUp(int rt) {
    tree[rt] = tree[lc] + tree[rc];
}
void build(int L, int R, int rt) {
    if (L == R)
        tree[rt] = b[L] >= 0 ? b[L] : 0;
    else {
        int mid = L + R >> 1;
        build(L, mid, lc);
        build(mid + 1, R, rc);
        pushUp(rt);
    }
}
void modify(int L, int R, int pos, int rt) {
    if (L == R)
        tree[rt] = b[L] >= 0 ? b[L] : 0;
    else {
        int mid = L + R >> 1;
        if (pos <= mid)
            modify(L, mid, pos, lc);
        else
            modify(mid + 1, R, pos, rc);
        pushUp(rt);
    }
}
LL ask(int L, int R, int l, int r, int rt) {
    if (l > r)
        return 0;
    if (l <= L && R <= r)
        return tree[rt];
    else {
        int mid = L + R >> 1;
        LL res = 0;
        if (l <= mid)
            res += ask(L, mid, l, r, lc);
        if (r > mid)
            res += ask(mid + 1, R, l, r, rc);
        return res;
    }
}

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
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for (int i = 1; i <= n; i++) {
            b[i] = a[i] - a[i - 1];
            update(i, b[i]);
        }

        build(1, n, 1);

        for (;m--;) {
            int op, l, r, k;
            scanf("%d%d%d", &op, &l, &r);
            if (op == 1) {
                scanf("%d", &k);
                b[l] += k;
                update(l, k);
                modify(1, n, l, 1);
                if (r + 1 <= n) {
                    b[r + 1] -= k;
                    update(r + 1, -k);
                    modify(1, n, r + 1, 1);
                }
            } else {
                LL t = query(l);
                t += ask(1, n, l + 1, r, 1);
                printf("%lld\n", t);
            }
        }

        for (int i = 1; i <= n; i++)
            bits[i] = 0;
    }

    return 0;
}
