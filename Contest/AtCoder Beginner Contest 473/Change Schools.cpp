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
        int n, k; cin >> n >> k;
        vector<int> cnt(k + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            cnt[a]++;
        }

        int ans = 0;
        int cnt_mx = *max_element(cnt.begin() + 1, cnt.end());
        for (int i = 1; i <= k; i++) {
            if (cnt[i] >= cnt_mx - 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
}