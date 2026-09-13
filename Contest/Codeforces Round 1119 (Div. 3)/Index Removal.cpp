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
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        vector<ll> c(n), pref(n + 1, 0);;
        for (int i = 0; i < n; i++) c[i] = a[i] - 1LL * i * k, pref[i + 1] = pref[i] + c[i];

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                cout << 0 << " ";
            } else {
                ll need = c[i - 1] - k;
                int l = i + 1, r = n;

                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (c[mid] > need) l = mid + 1;
                    else r = mid;
                }

                ll cnt = l - (i + 1);
                cout << (pref[l] - pref[i + 1]) - cnt * need << " ";
            }
        }
        cout << '\n';
    }
}