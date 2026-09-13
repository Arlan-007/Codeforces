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

    ll N, S, L; cin >> N >> S >> L;
    vector<ll> a(N - 1), pref(N, 0);
    for (int i = 0; i < N - 1; i++) cin >> a[i], pref[i + 1] = pref[i] + a[i];

    int ans = 1;
    for (int l = 0; l < N; l++) {
        for (int r = l; r < N; r++) {
            if (l <= S - 1 && S - 1 <= r) {
                ll left = pref[S - 1] - pref[l], right = pref[r] - pref[S - 1];
                ll cost = 2 * min(left, right) + max(left, right);
                if (cost <= L) ans = max(ans, r - l + 1);
            }
        }
    }

    cout << ans << "\n";
}