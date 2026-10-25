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
#include <iomanip>
#include <stdexcept>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

long double dfs(int node , int par , const vector<vector<int>>& v) {
    long double sum = 0;
    ll cnt = 0;
    for (auto u : v[node]) if (u != par) cnt++, sum += dfs(u, node, v) + 1;
    if (cnt == 0) return 0;
    return sum / cnt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i=0 ; i<n-1 ; i++){
        int x , y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout << fixed << setprecision(12) <<  dfs(1 , -1  , v) << endl;
}