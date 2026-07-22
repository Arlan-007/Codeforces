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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll sum = 0, best = 0;

        for (int i = 0; i + 1 < n; i++)
            sum += abs(a[i] - a[i + 1]);

        if (n >= 2) {
            best = max(abs(a[0] - a[1]), abs(a[n - 1] - a[n - 2]));
        }

        for (int i = 1; i + 1 < n; i++) {
            ll gain = abs(a[i - 1] - a[i])
            + abs(a[i] - a[i + 1])
            - abs(a[i - 1] - a[i + 1]);

            best = max(best, gain);
        }

        cout << sum - best << '\n';
    }
}