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
        int n, a, sum = 0; cin >> n;
        bool flg = false, mid = false;

        for (int i = 0; i < n; i++) {
            cin >> a, sum += a;
            if (a > 1) {
                flg = true;
                if (i > 0 && i < n - 1) mid = true;
            }
        }

        if (!flg) cout << -1 << '\n';
        else if (mid) cout << sum - 1 << '\n';
        else cout << sum - n + 1 << '\n';
    }
}