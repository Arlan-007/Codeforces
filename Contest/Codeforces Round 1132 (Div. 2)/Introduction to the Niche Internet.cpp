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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());

        int cnt = 0, ptr = n - 1;
        while (a[ptr] == a[n - 1]) cnt++, ptr--;
        if (cnt > k) {
            cout << "NO" << "\n";
            continue;
        }

        cout << "YES" << "\n";
        for (int i = n - k; i < n; i++) cout << a[i] << ' ';
        for (int i = n - k - 1; i >= 0; i--) cout << a[i] << ' ';
        cout << "\n";
    }
}