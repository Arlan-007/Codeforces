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
        int n; cin >> n;
        vector<ll> a(n) , d(n-1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n - 1; i++) d[i] = a[i + 1] - a[i];

        int i = 0;
        auto par = [](ll x) { return ((x % 2) + 2) % 2; };
        while (i < n-1) {
            int k = i;
            while (k < n - 1 && par(d[k]) == par(d[i])) k++;
            sort (d.begin() + i, d.begin() + k);
            i = k;
        }

        cout << a[0] << " ";
        ll cur = a[0];
        for (int i = 0; i < n-1; i++) {
            cur += d[i];
            cout << cur << " ";
        }
        cout << endl;
    }
}