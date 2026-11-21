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

    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(3, 0), last(3, -1);
    for (char c : s) cnt[c - 'A']++;

    ll fs = -1, ans = 0;
    for (int i = 0; i < n; i++) {
        ll c = s[i] - 'A';
        cnt[c]--, last[c] = i;

        ll mn = min({last[0], last[1], last[2]});
        if (fs == -1 && mn >= 0) fs = i;
        if (fs != -1 && cnt[0] && cnt[1] && cnt[2]) ans += max(0LL, mn - fs);
    }
    cout << ans << '\n';
}