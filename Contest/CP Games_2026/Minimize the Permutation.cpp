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
        int n;
        cin >> n;
        vector<int> a(n), pos(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        vector<int> used(n - 1, 0);
        for (int val = 1; val <= n; val++) {
            int p = pos[val];
            while (p > 0 && !used[p - 1] && a[p - 1] > val) {
                used[p - 1] = 1;
                swap(a[p], a[p - 1]);
                pos[a[p]] = p;
                pos[a[p - 1]] = p - 1;
                p--;
            }
        }

        for (int x : a)
            cout << x << ' ';
        cout << '\n';
    }
}