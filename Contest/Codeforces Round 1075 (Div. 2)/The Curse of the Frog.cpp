#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static auto _speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;

        i128 freeDist = 0;
        ll bestNet = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;

            // Free jumps before first rollback for this type
            freeDist += (i128)(b - 1) * a;

            // Net gain per rollback cycle
            ll net = b * a - c;
            bestNet = max(bestNet, net);
        }

        // If free distance already enough
        if (freeDist >= x) {
            cout << 0 << "\n";
            continue;
        }

        // If no positive net cycles, impossible
        if (bestNet <= 0) {
            cout << -1 << "\n";
            continue;
        }

        // Binary search on number of rollbacks
        ll lo = 1, hi = (ll)1e18;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;

            i128 total = freeDist + (i128)mid * bestNet;

            if (total >= x) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}