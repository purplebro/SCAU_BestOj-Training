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
typedef pair<int, int> pii;
const int N = 2000 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-4;

int n;
char s[N];

inline void add(int &x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
struct Matrix {
    int mat[27][27];
    Matrix () {}
    Matrix (int n) {
        mst(mat, 0);
        for (int i = 0; i < 27; i++)
            mat[i][i] = 1;
        for (int i = 0; i < 27; i++)
            mat[i][n] = 1;
    }
    Matrix operator * (const Matrix &b) {
        Matrix c;
        mst(c.mat, 0);
        for (int k = 0; k < 27; k++) {
            for (int i = 0; i < 27; i++) if (mat[i][k]) {
                for (int j = 0; j < 27; j++) if (b.mat[k][j])
                    add(c.mat[i][j], 1LL * mat[i][k] * b.mat[k][j] % mod);
            }
        }
        return c;
    }
}p[27];

int main() {
#ifdef purple_bro
    freopen("in.txt","r",stdin);
#endif
    for (int i = 0; i < 26; i++)
        p[i] = Matrix(i);

    scanf("%d%s", &n, s + 1);

    Matrix ans;
    mst(ans.mat, 0);

    for (int i = 0; i < 27; i++)
        ans.mat[i][i] = 1;

    for (int i = n; i >= 1; i--)
        ans = ans * p[s[i] - 'a'] * ans;

    int res = 0;

    for (int i = 0; i < 26; i++)
        add(res, ans.mat[26][i]);

    printf("%d\n", res);

    return 0;
}
