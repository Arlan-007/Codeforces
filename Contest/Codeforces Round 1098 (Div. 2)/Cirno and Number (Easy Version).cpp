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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll a; int n, d1, d2;
        cin >> a >> n >> d1 >> d2;

        string s = to_string(a);
        int L = s.size();
        ll ans = LLONG_MAX;

        auto trial = [&](string b) {
            if (b.size() > 1 && b[0] == '0') return;
            ans = min(ans, abs(a - stoll(b)));
        };

        int cnt = 0;
        while (cnt < L && (s[cnt]-'0' == d1 || s[cnt]-'0' == d2)) cnt++;
        if (cnt == L) {
            ans = 0;
        } else {
            int c = s[cnt] - '0', rest = L - cnt - 1;
            string pref = s.substr(0, cnt);

            if (d2 < c) trial(pref + char('0'+d2) + string(rest, '0'+d2));
            else if (d1 < c) trial(pref + char('0'+d1) + string(rest, '0'+d2));

            if (d1 > c) trial(pref + char('0'+d1) + string(rest, '0'+d1));
            else if (d2 > c) trial(pref + char('0'+d2) + string(rest, '0'+d1));

            for (int i = cnt - 1; i >= 0; --i) {
                int x = s[i] - '0';
                if (x == d1) {
                    trial(s.substr(0, i) + char('0' + d2) + string(L - i - 1, char('0' + d1)));
                    break;
                }
                if (x == d2) {
                    trial(s.substr(0, i) + char('0' + d1) + string(L - i - 1, char('0' + d2)));
                    break;
                }
            }
        }
        if (L > 1) trial(string(L-1, '0'+d2));
        if (d1 > 0) trial(string(L+1, '0'+d1));
        else trial(char('0'+d2) + string(L, '0'+d1));

        cout << ans << "\n";
    }
}