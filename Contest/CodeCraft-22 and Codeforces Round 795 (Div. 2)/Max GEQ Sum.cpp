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
#define int long long

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

bool chk(vector<int>& a) {
    vector<pair<int, int>> st;
    int sum = 0;

    for (int x : a) {
        int mn = sum;
        while (!st.empty() && st.back().first <= x) mn = min(mn, st.back().second), st.pop_back();
        if (mn < sum) return false;
        st.push_back({x, sum}), sum += x;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        bool ans = chk(a);
        reverse(a.begin(), a.end());
        cout << (ans && chk(a) ? "YES" : "NO") << '\n'; 
    }
}
