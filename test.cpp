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
        int n; cin >> n;
        int xo = 0;
        vector<ll> cnt(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            xo ^= x;

            for (int j = 0; j < 30; j++) {
                int k = (x >> j) & 1;
                cnt[j] += k;
            }
        }

        if (n == 1) cout << "0\n";
        else if (xo == 0) cout << "1\n";
        else {
            int h = log2(xo);
            cout << cnt[h] << "\n";
        }
    }
}