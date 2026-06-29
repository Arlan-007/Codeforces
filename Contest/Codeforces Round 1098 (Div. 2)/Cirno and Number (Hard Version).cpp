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
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a;
        int n;
        cin >> a >> n;

        vector<int> d(n);
        for (int &x : d) cin >> x;

        string s = to_string(a);
        int L = s.size();
        long long ans = LLONG_MAX;

        auto trial = [&](const string &b) {
            if (b.size() > 1 && b[0] == '0') return;
            ans = min(ans, llabs(a - stoll(b)));
        };

        int mn = d[0], mx = d.back();
        int p = 0;
        while (p < L && binary_search(d.begin(), d.end(), s[p] - '0')) p++;

        if (p == L) ans = 0;
        else {
            for (int i = p; i >= 0; --i) {
                auto it = upper_bound(d.begin(), d.end(), s[i] - '0');
                if (it != d.end()) {
                    int y = *it;
                    trial(s.substr(0, i) + char('0' + y) + string(L - i - 1, char('0' + mn)));
                    break;
                }
            }

            for (int i = p; i >= 0; --i) {
                auto it = lower_bound(d.begin(), d.end(), s[i] - '0');
                if (it != d.begin()) {
                    --it;
                    int y = *it;
                    trial(s.substr(0, i) + char('0' + y) + string(L - i - 1, char('0' + mx)));
                    break;
                }
            }
        }

        if (L > 1) {
            if (mx) trial(string(L - 1, char('0' + mx)));
            else trial("0");
        }
        if (mn) trial(string(L + 1, char('0' + mn)));
        else if (n > 1) trial(char('0' + d[1]) + string(L, char('0' + mn)));

        cout << ans << '\n';
    }
}