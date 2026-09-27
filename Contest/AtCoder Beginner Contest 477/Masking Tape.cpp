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
    cout.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<bool> tile(n + 1, false);
    vector<char> col(n + 1, 'a');
    vector<int> vis(n + 1, 0);
    char C = 'a';
    int v = 0;

    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int x; cin >> x;
            if (!tile[x]) {
                if (vis[x] != v) {
                    col[x] = C;
                    vis[x] = v;
                }
                tile[x] = true;
            } else {
                tile[x] = false;
                vis[x] = v;
            }
        }
        else {
            cin >> C, v++;
        }
    }

    for (int x = 1; x <= n; ++x) {
        if (tile[x]) cout << col[x];
        else cout << (vis[x] == v ? col[x] : C);
    }
    cout << '\n';
}