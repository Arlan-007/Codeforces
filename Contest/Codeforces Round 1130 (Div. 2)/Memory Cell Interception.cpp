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

vector<ll> solve(string s, string t) {
    ll n = s.size(), m = t.size(), val = 0;
    vector<ll> pos, gaps, ans;
    for (int i = 0; i < m; i++) if (t[i] == 'W') pos.push_back(i + 1);
    for (int i = 1; i < pos.size(); i++) gaps.push_back(pos[i] - pos[i - 1]);
    sort(gaps.begin(), gaps.end());

    vector<ll> pref(gaps.size() + 1);
    for (int i = 0; i < gaps.size(); i++) pref[i + 1] = pref[i] + gaps[i];

    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            val = i + 1;
        } else if (val > 0) {
            ll mx = val + m;
            if (!pos.empty()) mx = max(mx, i + pos.back());
            ans.push_back(mx - val + 1);
        }
        else if (pos.empty()) {
            ans.push_back(1);
        }
        else {
            ll len = i + 1;
            int k = upper_bound(gaps.begin(), gaps.end(), len) - gaps.begin();
            ll sum = pref[k] + 1LL * (gaps.size() - k) * len;
            ans.push_back(1 + len + sum);
        }
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        for (ll x : solve(s, t)) cout << x << ' '; cout << '\n';
        for (ll x : solve(t, s)) cout << x << ' '; cout << '\n';
    }
}