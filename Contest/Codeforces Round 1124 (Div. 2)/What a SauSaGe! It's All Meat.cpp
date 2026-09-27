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

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

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
        int n, q; cin >> n >> q;
        vector<int> a(n);
        vector<int> ok(16);
        for (int x : {0, 3, 5, 6, 9, 10, 12, 15}) ok[x] = 1;

        int ans = 0;
        for (int &x : a) {
            cin >> x;
            ans += ok[x];
        }

        cout << ans << ' ';
        while (q--) {
            int p, x; cin >> p >> x; p--;
            ans -= ok[a[p]]; a[p] = x; ans += ok[a[p]];
            cout << ans << ' ';
        }
        cout << '\n';
    }
}