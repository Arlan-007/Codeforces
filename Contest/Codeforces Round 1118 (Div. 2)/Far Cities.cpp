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

int n, cur;

int ask(int u, int v, int d) {
    cout << "? " << u << ' ' << v << ' ' << d << endl;
    int x; cin >> x;
    return x;
}

int find_farthest(int s, int best) {
    for (int v = 1; v <= n; ++v)
        while (ask(s, v, cur + 1)) cur++, best = v;
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n; cur = 0;
        int u = find_farthest(1, 1);
        int v = find_farthest(u, 1);
        cout << "! " << u << ' ' << v << ' ' << cur << endl;
    }
}