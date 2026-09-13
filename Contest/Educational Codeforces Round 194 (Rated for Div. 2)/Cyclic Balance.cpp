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

    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<vector<int>> bianca(n - 1, vector<int>(4, 0));

    for (int i = 0; i < n - 1; i++) {
        int type = (s[i] - '0') * 2 + (s[i + 1] - '0');
        if (i > 0) for (int j = 0; j < 4; j++) bianca[i][j] = bianca[i - 1][j];
        bianca[i][type]++;
    }

    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        int len = r - l + 1;
        if (len == 1) {
            cout << 3 << "\n";
            continue;
        }

        vector<int> cnt(4, 0);
        for (int j = 0; j < 4; j++) cnt[j] = bianca[r - 1][j] - (l > 0 ? bianca[l - 1][j] : 0);
        int ext = (s[r] - '0') * 2 + (s[l] - '0'); cnt[ext]++;
        if (cnt[3] > cnt[0]) swap(cnt[0], cnt[3]);

        int ans = 0, ops = 0;
        if (cnt[0] > cnt[1]) {
            ops = (cnt[0] - cnt[1] + 1) / 2;
            ans += ops; cnt[0] -= ops; cnt[1] += ops;
        }
        if (cnt[3] > cnt[1]) {
            cnt[1] -= ops; cnt[0] += ops + cnt[3]; ans -= ops;
            ops = (cnt[0] - 2 * cnt[1] + 2) / 3;
            cnt[1] += ops; cnt[0] -= ops;
            ans += ops + (cnt[1] * 2 - cnt[0]);
            cnt[0] = cnt[1]; cnt[3] = cnt[1];
        }
        cout << ans + 2 * cnt[1] - cnt[0] - cnt[3] << '\n';
    }
}