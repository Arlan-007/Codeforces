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
        ll n, sum = 0, ext = 0; cin >> n;
        string s, ans; cin >> s;

        for (char c : s) sum += c - '0';
        for (int i = n - 1; i >= 0; i--) {
            int x = sum + ext;
            ans += char('0' + x % 10);
            ext = x / 10;
            sum -= s[i] - '0';
        }

        while (ext) {
            ans += char('0' + ext % 10);
            ext /= 10;
        }

        while (ans.size() > 1 && ans.back() == '0') ans.pop_back();

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}