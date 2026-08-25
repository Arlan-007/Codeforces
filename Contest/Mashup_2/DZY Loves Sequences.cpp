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
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> l(n, 1), r(n, 1);;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i-1]) l[i] = l[i-1] + 1;
        for (int i = n-2; i >= 0; i--)
            if (a[i] < a[i+1]) r[i] = r[i+1] + 1;

        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, l[i] + 1),
            ans = max(ans, r[i] + 1);

        for (int i = 1; i < n-1; i++)
            if (a[i-1] + 1 < a[i+1]) ans = max(ans, l[i-1] + 1 + r[i+1]);
        ans = min(ans, n);
        cout << ans << '\n';
    }
}