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
        vector<ll> a(n + 1), b(n + 1, NEG), c(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> c[i];

        bool ans = true;
        for (int i = 2; i <= n; i++) if (c[i] < c[i - 1]) ans = false;
        b[1] = c[1];

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '1') b[i] = b[i - 1] + a[i];
            else {
                if (c[i] > c[i - 1]) b[i] = c[i];
                else b[i] = b[i - 1];
                a[i] = b[i] - b[i - 1];
            }

            if (b[i] > c[i]) ans = false;
            if (c[i] > c[i - 1] && b[i] != c[i]) ans = false;
        }

        ll sum = 0, mx = NEG;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            mx = max(mx, sum);
            if (sum != b[i] || mx != c[i]) ans = false;
        }

        if (ans) {
            cout << "Yes" << "\n";
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << '\n';
        } else cout << "No" << '\n';
    }
}