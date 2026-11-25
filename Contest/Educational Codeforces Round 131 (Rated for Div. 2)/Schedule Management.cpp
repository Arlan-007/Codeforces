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
        int n, m; cin >> n >> m;
        vector<int> cnt(n), freq(m + 1);
        for (int i = 0, x; i < m; ++i) {
            cin >> x;
            cnt[x - 1]++;
        }
        for (int x : cnt) freq[x]++;

        int extra = m, help = 0;
        int seen[2] = {freq[0], 0};
        bool found = false;

        for (int T = 0; ; T++) {
            if (found) break;
            if (help >= extra) {
                cout << T << '\n';
                found = true;
            }
            help += seen[1 - T % 2];
            extra -= n - seen[0] - seen[1];
            seen[(T + 1) % 2] += freq[T + 1];
        }
    }
}