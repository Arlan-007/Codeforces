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
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        for (int i = 0; i < n; i++) {
            int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            cout << b[j] - a[i] << " ";
        }
        cout << "\n";

        vector<ll> mx(n);
        int last = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = b[last] - a[i];
            if (i && b[i - 1] < a[i])
                last = i - 1;
        }

        for (auto x : mx)
            cout << x << " ";
        cout << "\n";
    }
}