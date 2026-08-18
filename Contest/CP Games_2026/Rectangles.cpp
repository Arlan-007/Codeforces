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
        int n; cin >> n;
        vector<ll> x1(n), y1(n), x2(n), y2(n);
        for (int i = 0; i < n; i++) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

        int maxx1 = 0, minx2 = 0, maxy1 = 0, miny2 = 0;
        for (int i = 1; i < n; i++) {
            if (x1[i] > x1[maxx1]) maxx1 = i;
            if (x2[i] < x2[minx2]) minx2 = i;
            if (y1[i] > y1[maxy1]) maxy1 = i;
            if (y2[i] < y2[miny2]) miny2 = i;
        }
        for (int s : {-1, maxx1, minx2, maxy1, miny2}) {
            ll X1 = NEG, X2 = INF, Y1 = NEG, Y2 = INF;
            for (int i = 0; i < n; i++) {
                if (i == s) continue;
                X1 = max(X1, x1[i]);  X2 = min(X2, x2[i]);
                Y1 = max(Y1, y1[i]);  Y2 = min(Y2, y2[i]);
            }
            if (X1 <= X2 && Y1 <= Y2) { cout << X1 << " " << Y1 << "\n"; return 0; }
        }
    }
}