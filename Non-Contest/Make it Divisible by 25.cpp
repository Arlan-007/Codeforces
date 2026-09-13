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
        string s; cin >> s;
        vector<string> sub = {"00", "25", "50", "75"};
        ll n = s.length();

        ll ans = n;
        for (int i = 3; i >= 0; i--) {
            int j = n - 1;
            while (j >= 0 && s[j] != sub[i][1]) j--;
            if (--j < -1) continue;
            while (j >= 0 && s[j] != sub[i][0]) j--;
            if (j < 0) continue;
            ans = min(ans, n - j - 2);
        }

        cout << ans << endl;
    }
}