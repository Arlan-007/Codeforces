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
        int n, k; cin >> n >> k;

        if (k < n || k == 2 * n) {
            cout << -1 << '\n';
            continue;
        }

        int x = k - n;
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) a[i][i] = i <= x ? 2 * i + 1 : i + x + 1;
        for (int i = 1; i <= x; i++) a[i - 1][i] = 2 * i;

        int cur = k + 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 0) a[i][j] = cur++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << a[i][j] << " ";
            cout << '\n';
        }
    }
}