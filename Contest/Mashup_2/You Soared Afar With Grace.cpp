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
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vector<pair<int,int>> ops;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[n - 1 - i]) {
                for (int j = i + 1; j < n - i; j++) {
                    if (a[j] == b[n - 1 - i] && b[j] == a[n - 1 - i]) {
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                        ops.push_back({i + 1, j + 1});
                        break;
                    }
                }
            }
        }
        if (a == vector<int>(b.rbegin(), b.rend())) {
            cout << ops.size() << "\n";
            for (auto [i, j] : ops)
                cout << i << " " << j << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}