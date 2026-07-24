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
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n + 1);
        map<int,int> f1, f2;

        int L1 = 1, L2 = 1, dist = 0;
        ll ans = 0;

        for (int R = 1; R <= n; R++) {
            cin >> a[R];

            if (++f1[a[R]] == 1) dist++;
            f2[a[R]]++;

            while (dist > k)
                if (--f1[a[L1++]] == 0) dist--;

            while (L2 < L1 || f2[a[L2]] > 1)
                f2[a[L2++]]--;

            if (dist == k) {
                int x = max(L1, R - r + 1);
                int y = min(L2, R - l + 1);
                if (x <= y) ans += y - x + 1;
            }
        }

        cout << ans << '\n';
    }
}