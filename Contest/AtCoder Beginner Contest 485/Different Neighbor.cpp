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

    int n; cin >> n;
    vector<int> c(n);
    for (int& x : c) cin >> x;

    for (int l = 0; l < n;) {
        int r = l;
        while (r + 1 < n && c[r + 1] == c[l]) r++;

        for (int i = l; i <= r; i++) {
            int L = l > 0 ? i - l + 1 : n;
            int R = r + 1 < n ? r - i + 1 : n;
            cout << min(L, R) << ' ';
        }
        l = r + 1;
    }
}