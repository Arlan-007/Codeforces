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
        int n;
        cin >> n;

        vector<ll> a(n), suf(n);
        ll total = 0;

        for (auto &x : a) {
            cin >> x;
            total += x;
        }

        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = min(a[i], suf[i + 1]);
        }

        ll sufsum = 0;
        for (ll x : suf) sufsum += x;
        ll move = total - sufsum;

        ll best = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && suf[i] == suf[i - 1]) len++;
            else len = 1;

            if (a[i] == suf[i]) {
                best = max(best, len);
            }
        }

        cout << move + max(0LL, best - 1) << '\n';
        
    }
}