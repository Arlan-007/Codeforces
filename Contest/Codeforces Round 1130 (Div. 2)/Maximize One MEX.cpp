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

int mex(const vector<int>& v, int p) {
    int n = v.size();
    vector<bool> seen(n + 1, false);

    for (int i = 0; i <= p; i++) seen[v[i]] = true;

    int mex = 0;
    while (seen[mex]) mex++;
    return mex;
}

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

        int p = n - k, best = mex(a, p), I = -1, J = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(a[i], a[j]);
                if (mex(a, p) > best) best = mex(a, p), I = i, J = j;
                swap(a[i], a[j]);
            }
        }

        if (I == -1) cout << -1 << '\n';
        else cout << I + 1 << ' ' << J + 1 << '\n';
    }
}