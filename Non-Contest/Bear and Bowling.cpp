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
    while (t--){
        int n; cin >> n;
        vector<ll> a(n + 1), kept(n + 1, 1), pref(n + 1);

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
            ans += 1LL * i * a[i];
        }

        bool flg = true;
        while (flg) {
            flg = false;
            int position = 1;

            for (int i = 1; i <= n; i++) {
                ll gain = 1LL * position * a[i] + pref[n] - pref[i];

                if (kept[i] && gain < 0) {
                    ans -= gain;
                    kept[i] = 0;
                    flg = true;
                }
                else if (!kept[i] && gain >= 0) {
                    ans += gain;
                    kept[i] = 1;
                    flg = true;
                }

                if (kept[i]) position++;
                pref[i] = pref[i - 1] + kept[i] * a[i];
            }
        }
        cout << ans << '\n';
    }
}