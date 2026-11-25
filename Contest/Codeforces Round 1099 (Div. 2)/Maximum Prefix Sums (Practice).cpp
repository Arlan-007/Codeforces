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

    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<ll> a(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        ll sum = 0, last = -1;
        bool ans = true;
        for (int i = 0; i < n && ans; i++) {
            if (i && c[i] < c[i - 1]) ans = false;

            if (s[i] == '0') a[i] = c[i] - sum, last = i;
            sum += a[i];

            if (sum > c[i]) {
                if (last == -1) ans = false;
                else a[last] -= sum - c[i], sum = c[i];
            }

            if (!i || c[i] > c[i - 1]) {
                if (sum != c[i]) ans = false;
                last = -1;
            }
        }

        if (ans) {
            cout << "Yes" << "\n";
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << '\n';
        } else cout << "No" << '\n';
    }
}