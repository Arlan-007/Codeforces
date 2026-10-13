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
        int n; cin >> n;
        vector<int> a(n), v;
        for (auto &x : a) cin >> x;
        map<int, int> mp;

        long long ans = 0;
        for (int i = 0; i < n - 4; i++) {
            int cur = a[i] + a[i + 2] - a[i + 4];
            ans += mp[cur];
            if (i >= 2 && v[i - 2] == cur) ans--;
            if (i >= 4 && v[i - 4] == cur) ans--;
            mp[cur]++;
            v.push_back(cur);
        }
        cout << ans << endl;
    }
}