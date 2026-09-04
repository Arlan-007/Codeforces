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
    vector<pair<pair<int, int>, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first.first >> points[i].first.second;
        points[i].second = i;
        points[i].first.first /= 1000;
    }

    sort(points.begin(), points.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
        return a.first.first < b.first.first || (a.first.first == b.first.first && (a.first.first % 2 == 0 ? (a.first.second < b.first.second) : (a.first.second > b.first.second)));
    });

    for (auto pt : points) cout << pt.second + 1 << " ";
    
}