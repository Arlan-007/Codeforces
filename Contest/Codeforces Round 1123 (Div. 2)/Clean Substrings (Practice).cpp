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
        int n, q; cin >> n >> q;
        string s; cin >> s;

        ll x = count(s.begin(), s.end(), '0'), sum = 0;
        for (int i = 1; i < n; i++) if (s[i - 1] != s[i]) sum += 1LL * i * (n - i);

        cout << (sum + x * (n - x)) / 2 << ' ';
        while (q--) {
            int i; cin >> i; i--;
            if (0 < i && i < n) sum += (s[i - 1] == s[i] ? 1LL : -1LL) * i * (n - i); i++;
            if (0 < i && i < n) sum += (s[i - 1] == s[i] ? 1LL : -1LL) * i * (n - i);

            x += s[i - 1] == '0' ? -1 : 1;
            s[i - 1] ^= 1;
            cout << (sum + x * (n - x)) / 2 << ' ';
        }
        cout << '\n';
    }
}