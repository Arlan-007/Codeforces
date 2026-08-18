#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <tuple>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <complex>
#include <bitset>
#include <random>
#include <limits>
#include <climits>
#include <cfloat>
#include <cassert>
#include <exception>
#include <stdexcept>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        vector<vector<char>> b(n, vector<char>(m , '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<vector<int>> lt(n, vector<int>(m)), rt(n, vector<int>(m));
        vector<vector<int>> up(n, vector<int>(m)), dn(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) {if (a[i][j] != '.') up[i][j] = up[i - 1][j] + 1;}
                else up[i][j] = a[i][j] != '.';

                if (j > 0) {if (a[i][j] != '.') lt[i][j] = lt[i][j - 1] + 1;}
                else lt[i][j] = a[i][j] != '.';
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i < n - 1) {if (a[i][j] != '.') dn[i][j] = dn[i + 1][j] + 1;}
                else dn[i][j] = a[i][j] != '.';

                if (j < m - 1) {if (a[i][j] != '.') rt[i][j] = rt[i][j + 1] + 1;}
                else rt[i][j] = a[i][j] != '.';
            }
        }

        vector<tuple<int,int,int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '*') {
                    int len = min(min(up[i][j], lt[i][j]), min(dn[i][j], rt[i][j])) - 1;
                    if (len != 0) ans.push_back(make_tuple(i, j, len));
                }
            }
        }
        for (auto [r, c, s] : ans) {
            b[r][c] = '*';

            for (int k = 1; k <= s; k++) {
                b[r-k][c] = '*';
                b[r+k][c] = '*';
                b[r][c-k] = '*';
                b[r][c+k] = '*';
            }
        }

        if (b != a) cout << -1 << '\n';
        else {
            cout << ans.size() << '\n';
            for (auto [r, c, s] : ans) cout << r+1 << ' ' << c+1 << ' ' << s << '\n';
        }
    }
}