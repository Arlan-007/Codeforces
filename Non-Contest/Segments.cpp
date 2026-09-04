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

    int n; cin >> n;
    vector<pair<int, int>> inter;

    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        pair<int, int> merged = {l, r};
        vector<pair<int, int>> new_;

        for (auto& interval : inter) {
            if (max(merged.first, interval.first) <= min(merged.second, interval.second)) {
                merged.first = min(merged.first, interval.first);
                merged.second = max(merged.second, interval.second);
            } else {
                new_.push_back(interval);
            }
        }
        new_.push_back(merged);
        inter = new_;

        cout << inter.size() << "\n";
    }
}