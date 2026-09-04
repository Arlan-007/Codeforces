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

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

int root[200005], sz[200005];

int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);
    root[y] = x; sz[x] += sz[y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        auto zero = [&](int i, int j) -> bool {
            if (i == j) return s[j] == '1';
            return s[j] == '0';
        };

        int tot = n * n;
        for (int i = 0; i < tot; i++) {
            root[i] = i;
            sz[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!zero(i, j)) continue;
                int cur = i * n + j;
                if (j + 1 < n && zero(i, j + 1)) unite(cur, i * n + j + 1);
                if (i + 1 < n && zero(i + 1, j)) unite(cur, (i + 1) * n + j);
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (zero(i, j)) {
                    int rt = find(i * n + j);
                    mx = max(mx, sz[rt]);
                }
            }
        }
        cout << mx << '\n';

    }
}