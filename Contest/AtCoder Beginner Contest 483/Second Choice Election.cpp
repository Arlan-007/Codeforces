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

    int n, m, a, b; cin >> n >> m;
    vector<vector<int>> sec(n + 1);
    vector<pair<int, int>> score(n + 1);
    for (int i = 1; i <= n; i++) score[i].second = -i;

    while (m--) cin >> a >> b, score[a].first++, sec[a].push_back(b);

    auto leader = *max_element(score.begin() + 1, score.end());
    for (int k = 1; k <= n; k++) {
        auto best = leader;
        if (k == -leader.second) {
            best = {-1, 0};
            for (int i = 1; i <= n; i++) if (i != k) best = max(best, score[i]);
        }
        for (int b : sec[k]) score[b].first++, best = max(best, score[b]);
        cout << -best.second << '\n';
        for (int b : sec[k]) --score[b].first;
    }
}