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
        ll k, cur = 9, len = 1; cin >> k;
        while (k - cur * len > 0) k -= cur * len, cur *= 10, len++;
        string s = to_string(cur / 9 + (k - 1) / len);

        ll ans = 0, p = 0;;
        for (int i = 0; i < (k - 1) % len + 1; i++) ans += s[i] - '0';
        for (int i = 0; i < s.length(); i++) {
            int x = s[i] - '0';
            if (x) ans += x * (len - 1) * cur / 2 + x * (2 * p + x - 1) / 2 * cur / 9;
            cur /= 10, p += x, len--;
        }
        cout << ans << '\n';
    }
}