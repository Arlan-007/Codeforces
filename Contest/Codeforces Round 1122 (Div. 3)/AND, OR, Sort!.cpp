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
        int n, zeros = 0; cin >> n;
        string s; cin >> s;
        for (int i = 0; i < s.length(); i++) zeros += s[i] == '0';

        int ans = INT_MAX, one = 0, zero = zeros;
        for (int i  = 0; i < s.length(); i++) {
            one += s[i] == '1';
            zero -= s[i] == '0';
            ans = min(ans, one + zero);
        }
        if (s[0] == '1') cout << zeros << endl;
        else cout << ans << endl;
    }
}