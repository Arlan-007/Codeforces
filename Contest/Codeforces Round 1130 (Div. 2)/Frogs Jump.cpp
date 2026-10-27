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
        int n, pairs = 0; cin >> n;
        string a, b; cin >> a >> b;
        int x = count(a.begin(), a.end(), 'f'), y = count(b.begin(), b.end(), 'f');

        string s = x >= y ? a : b;
        for (int i = 0; i + 1 < n; i++) if (s[i] == 'f' && s[i + 1] == 'f') pairs++, i++;
        cout << x + y - 2 * (min(x, y) + min(pairs, abs(x - y) / 2)) << '\n';
    }
}