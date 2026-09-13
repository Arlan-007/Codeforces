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

    int h, w; cin >> h >> w;
    vector<string> s(h), t(w, string(h, '.'));
    for (auto &x : s) cin >> x;

    if (h > w) {
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                t[j][i] = s[i][j];

        s = t;
        swap(h, w);
    }

    ll ans = 1;
    vector<int> good(w), pref(w + 1);
    for (int i = 0; i < h; i++) {
        fill(good.begin(), good.end(), 0);

        for (int k = i; k < h; k++) {
            for (int j = 0; j < w; j++)
                if (s[k][j] == '.') good[j] = 1;

            for (int j = 0; j < w; j++) pref[j + 1] = good[j], pref[j + 1] += pref[j];

            int lst = -1, lsb = -1;
            for (int r = 0; r < w; r++) {
                if (!good[r]) continue;
                if (s[i][r] == '.') lst = r;
                if (s[k][r] == '.') lsb = r;

                int x = min(lst, lsb);
                if (x != -1) ans += pref[x + 1];
            }
        }
    }
    cout << ans << '\n';
}