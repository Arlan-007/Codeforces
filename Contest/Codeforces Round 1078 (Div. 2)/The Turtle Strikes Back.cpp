#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        vector<vector<ll>> f(n, vector<ll>(m, NEG_INF));
        f[0][0] = a[0][0];
        for (int j = 1; j < m; ++j) f[0][j] = f[0][j-1] + a[0][j];
        for (int i = 1; i < n; ++i) f[i][0] = f[i-1][0] + a[i][0];
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                f[i][j] = a[i][j] + max(f[i-1][j], f[i][j-1]);
        vector<vector<ll>> g(n, vector<ll>(m, NEG_INF));
        g[n-1][m-1] = a[n-1][m-1];
        for (int j = m-2; j >= 0; --j) g[n-1][j] = g[n-1][j+1] + a[n-1][j];
        for (int i = n-2; i >= 0; --i) g[i][m-1] = g[i+1][m-1] + a[i][m-1];
        for (int i = n-2; i >= 0; --i)
            for (int j = m-2; j >= 0; --j)
                g[i][j] = a[i][j] + max(g[i+1][j], g[i][j+1]);
        vector<vector<ll>> crossH(n, vector<ll>(m, NEG_INF));
        vector<vector<ll>> crossV(n, vector<ll>(m, NEG_INF));

        for (int r = 0; r < n; ++r) {
            for (int j = 1; j < m; ++j) {
                crossH[r][j] = f[r][j-1] + g[r][j];
            }
        }
        for (int c = 0; c < m; ++c) {
            for (int i = 1; i < n; ++i) {
                crossV[i][c] = f[i-1][c] + g[i][c];
            }
        }
        struct Pair { ll val; int idx; };
        vector<Pair> top1H(m, {NEG_INF, -1}), top2H(m, {NEG_INF, -1});
        for (int j = 1; j < m; ++j) {
            for (int r = 0; r < n; ++r) {
                ll v = crossH[r][j];
                if (v > top1H[j].val) {
                    top2H[j] = top1H[j];
                    top1H[j] = {v, r};
                } else if (v > top2H[j].val) {
                    top2H[j] = {v, r};
                }
            }
        }

        vector<Pair> top1V(n, {NEG_INF, -1}), top2V(n, {NEG_INF, -1});
        for (int i = 1; i < n; ++i) {
            for (int c = 0; c < m; ++c) {
                ll v = crossV[i][c];
                if (v > top1V[i].val) {
                    top2V[i] = top1V[i];
                    top1V[i] = {v, c};
                } else if (v > top2V[i].val) {
                    top2V[i] = {v, c};
                }
            }
        }

        ll answer = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ll best_col_cross = NEG_INF;
                if (j >= 1) {
                    if (top1H[j].idx != i) best_col_cross = top1H[j].val;
                    else best_col_cross = top2H[j].val;
                }
                ll best_row_cross = NEG_INF;
                if (i >= 1) {
                    if (top1V[i].idx != j) best_row_cross = top1V[i].val;
                    else best_row_cross = top2V[i].val;
                }

                ll avoid = max(best_col_cross, best_row_cross);
                ll through = f[i][j] + g[i][j] - a[i][j];
                ll flipped_through = through - 2LL * a[i][j];
                ll candidate = max(avoid, flipped_through);
                answer = min(answer, candidate);
            }
        }
        cout << answer << '\n';
    }

    return 0;
}
