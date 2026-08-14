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

        vector<tuple<int,int,int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != '*') continue;
                int k = 1;
                while (i-k >= 0 && i+k < n && j-k >= 0 && j+k < m && a[i-k][j]=='*' && a[i+k][j]=='*' && a[i][j-k]=='*' && a[i][j+k]=='*') k++;
                k--;
                if (k >= 1) {
                    ans.push_back({i+1, j+1, k});
                    for (int d = 0; d <= k; d++) b[i-d][j] = b[i+d][j] = b[i][j-d] = b[i][j+d] = '*';
                }
            }
        }
        if (b != a) cout << -1 << '\n';
        else {
            cout << ans.size() << '\n';
            for (auto [r, c, s] : ans) cout << r << ' ' << c << ' ' << s << '\n';
        }
    }
}