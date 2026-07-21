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
        ll n,m; cin >> n >> m;
        int c2 = 0, c5 = 0;
        ll x = n;
        while (x % 2 == 0) {c2++;x /= 2;}
        while (x % 5 == 0) {c5++;x /= 5;}

        ll k = 1;
        while (c2 < c5 && k * 2 <= m) {k *= 2;c2++;}
        while (c5 < c2 && k * 5 <= m) {k *= 5;c5++;}
        while (k * 10 <= m) {k *= 10;}
        k *= (m / k);
        cout << n * k << '\n';
    }
}