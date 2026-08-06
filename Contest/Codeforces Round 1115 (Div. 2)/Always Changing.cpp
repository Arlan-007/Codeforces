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
        int n; cin >> n;
        string s; cin >> s;
        int cnt[2] = {0, 0}, blk[2] = {0, 0};
        for (int i = 0; i < n; i++) {
            cnt[s[i] - '0']++;
            if (i == 0 || s[i] != s[i-1]) blk[s[i] - '0']++;
        }

        int d0 = cnt[0] - blk[0], d1 = cnt[1] - blk[1];
        int k = abs(d0 - d1);

        if (k <= 1) {
            cout << d0 + d1 << "\n";
            continue;
        }

        char c = (d0 < d1) ? '0' : '1';
        int ext = 0;
        if (s[0] == c) ext++;
        if (s[n-1] == c && blk[0] + blk[1] > 1) ext++;
        if (k - ext <= 1) cout << d0 + d1 + k - 1 << "\n";
        else cout << -1 << "\n";
    }
}