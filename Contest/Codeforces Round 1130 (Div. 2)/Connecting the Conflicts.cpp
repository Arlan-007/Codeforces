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
        int k; cin >> k;
        vector<vector<vector<int>>> trees(k);
        for (int i = 0; i < k; i++) {
            int n; cin >> n;
            trees[i].assign(n, {});
            for (int j = 0; j < n - 1; j++) {
                int x, y; cin >> x >> y; x--, y--;
                trees[i][x].push_back(y);
                trees[i][y].push_back(x);
            }
        }

        int I = -1, J = -1;
        for (int i = 0; i < k && I == -1; i++)
            if (trees[i].size() > 1)
                for (int j = 0; j < trees[i].size() && I == -1; j++)
                    if (trees[i][j].size() == 1) I = i, J = trees[i][j][0];

        if (I == -1) I = J = 0;
        for (int i = 0; i < k; i++) {
            if (i == I) continue;
            cout << i + 1 << " 1 " << I + 1 << " " << J + 1 << "\n";
        }
    }
}