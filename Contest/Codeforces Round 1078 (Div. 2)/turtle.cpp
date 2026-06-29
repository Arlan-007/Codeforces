#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

using ll = long long;
const ll NEG = -(1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;

        vector<vector<ll>> a(n, vector<ll>(m));
        for (auto &r : a)
            for (auto &x : r)
                cin >> x;

        vector<vector<ll>> f(n, vector<ll>(m, NEG));
        vector<vector<ll>> g(n, vector<ll>(m, NEG));
        f[0][0] = a[0][0];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) {
                if (i) f[i][j] = max(f[i][j], f[i-1][j] + a[i][j]);
                if (j) f[i][j] = max(f[i][j], f[i][j-1] + a[i][j]);
            }
        g[n-1][m-1] = a[n-1][m-1];
        for (int i=n-1;i>=0;i--)
            for (int j=m-1;j>=0;j--) {
                if (i+1<n) g[i][j] = max(g[i][j], g[i+1][j] + a[i][j]);
                if (j+1<m) g[i][j] = max(g[i][j], g[i][j+1] + a[i][j]);
            }
        vector<vector<ll>> L = f, U = f, R = g, D = g;

        for (int i=0;i<n;i++)
            for (int j=1;j<m;j++)
                L[i][j] = max(L[i][j], L[i][j-1]);

        for (int j=0;j<m;j++)
            for (int i=1;i<n;i++)
                U[i][j] = max(U[i][j], U[i-1][j]);

        for (int i=0;i<n;i++)
            for (int j=m-2;j>=0;j--)
                R[i][j] = max(R[i][j], R[i][j+1]);

        for (int j=0;j<m;j++)
            for (int i=n-2;i>=0;i--)
                D[i][j] = max(D[i][j], D[i+1][j]);

        ll ans = LLONG_MAX;

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {

                ll avoid = NEG;

                if (i>0 && j>0)
                    avoid = max(avoid, U[i-1][j] + R[i][j+1]);

                if (i>0 && j>0)
                    avoid = max(avoid, L[i][j-1] + D[i+1][j]);

                ll through = f[i][j] + g[i][j] - a[i][j];
                ll flipped = through - 2*a[i][j];

                ans = min(ans, max(avoid, flipped));
            }
        }

        cout << ans << "\n";
    }
}
