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
    // cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        vector<int> ans(n);
        int left = 0;
        int right = n - 1;
        for (int cur = 1; cur < n; cur++) {
            ll perms = 1LL << (n - cur - 1);
            if (m <= perms) {
                ans[left++] = cur;
            } else {
                ans[right--] = cur;
                m -= perms;
            }
        }

        ans[left] = n;
        for (int x : ans)
            cout << x << " ";
    }
}