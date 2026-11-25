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
        int n, k, d; cin >> n >> k >> d;
        vector<int> a(n), b(k);;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> b[i];

        int ans = 0;
        for (int i = 0; i < min(d,2 * n); i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) cur += (a[j] == j + 1);
            cur += (d - i - 1)/2;

            ans  = max(ans, cur);

            for (int j = 0; j < b[i % k]; j++) a[j]++;
        }
        cout << ans << endl;
    }
}