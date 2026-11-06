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
        int n; cin >> n;
        vector<int> l(n + 1), r(n + 1), fs(n + 1, n + 1);
        for (int i = 2; i <= n; i++) cin >> l[i] >> r[i];

        for (int i = n; i >= 2; i--)
            for (int j = l[i]; j <= r[i]; j++) fs[j] = i;

        ll ans = 0;
        for (int i = 2; i <= n; i++)
            for (int j = l[i]; j <= r[i]; j++) ans += fs[j] > r[i];
        cout << ans << '\n';
    }
}