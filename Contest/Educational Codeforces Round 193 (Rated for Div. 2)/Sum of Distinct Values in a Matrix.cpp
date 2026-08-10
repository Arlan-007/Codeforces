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
    cin >> t;
    while (t--) {
        ll n, m, x, y; cin >> n >> m >> x >> y;
        vector<int> mark(n + m + 1, 0);
        for (int i = 0; i < x; i++) { int v; cin >> v; mark[v] += 1; }
        for (int i = 0; i < y; i++) { int v; cin >> v; mark[v] += 2; }
        
        ll ans = 0;
        int row = 0, Col = 0, total = 0, cap = n + m - 1;

        for (int v = n + m; v >= 1 && total < cap; v--) {
            if (!mark[v]) continue;
            if (mark[v] == 3) {
                total++;
                ans += v;
            }
            else if (mark[v] == 1) {
                if (row < n) {
                    row++;
                    total++;
                    ans += v;
                }
            }
            else {
                if (Col < m) {
                    Col++;
                    total++;
                    ans += v;
                }
            }
        }
        cout << ans << "\n";
    }
}