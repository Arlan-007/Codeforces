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

    vector<string> g(5);
    for (auto& x : g) cin >> x;

    int ans = 5;
    for (int i = 0; i < 5; i++) {
        int row = 0, col = 0;
        for (int j = 0; j < 5; j++) row += g[i][j] == '.', col += g[j][i] == '.';
        ans = min({ans, row, col});
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < 5; i++) d1 += g[i][i] == '.', d2 += g[i][5 - 1 - i] == '.';
    cout << min({ans, d1, d2}) << '\n';
}