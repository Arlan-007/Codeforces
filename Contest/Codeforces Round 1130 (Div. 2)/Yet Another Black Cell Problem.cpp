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
        int n, x; cin >> n >> x;
        vector<ll> a(n);
        for (ll &p : a) cin >> p;
        sort(a.begin(), a.end());

        auto check = [&](ll k) {
            vector<ll> b;
            for (int i = 0; i < n; i++)
                if ((i == 0 || a[i] - a[i - 1] > k) && (i == n - 1 || a[i + 1] - a[i] > k)) b.push_back(a[i]);

            int need = b.size();
            for (int i = 1; i < b.size(); i++) if (b[i] - b[i - 1] <= 2 * k) need--, i++;
            return need <= x;
        };

        ll lo = 1, hi = 1e9;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}