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
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.rbegin(), a.rend());

        ll ans = 1;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && a[i] == a[i + 1]) break;

            ll base = a[i] - 1, ways = 1;
            for (int e = i + 1; e > 0; e /= 2) {
                if (e & 1) ways = ways * base % MOD;
                base = base * base % MOD;
            }
            ans = (ans + ways) % MOD;
        }
        cout << ans << '\n';
    }
}