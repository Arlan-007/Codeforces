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
        int x, y, h = 1; cin >> x >> y;

        int com = x & y;
        if (com) {
            while (2 * h <= com) h *= 2;

            int D = 1 + x % h + y % h, b = 2 * h;
            while (b & (x | y)) b *= 2;

            int upX = b - x % b, upY = b - y % b;

            if (D <= min(upX, upY)) x -= D;
            else if (upX <= upY) x += upX;
            else y += upY;
        }
        cout << x << ' ' << y << '\n';
    }
}