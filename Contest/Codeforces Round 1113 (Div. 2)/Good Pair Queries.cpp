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

    int T = 1;
    cin >> T;
    while (T--) {
        int n, q; cin >> n >> q;
        string s, t; cin >> s >> t;

        vector<array<int,4>> p(n + 1, {0,0,0,0});
        for (int i = 0; i < n; i++) {
            p[i+1] = p[i];
            int type = (s[i]-'0')*2 + (t[i]-'0');
            p[i+1][type]++;
        }

        while (q--) {
            int l, r; cin >> l >> r; l--;
            int t1 = p[r][0]-p[l][0], t2 = p[r][1]-p[l][1];
            int t3 = p[r][2]-p[l][2], t4 = p[r][3]-p[l][3];
            cout << (abs(t2-t3) <= t1+t4 ? "YES" : "NO") << '\n';
        }
    }
}