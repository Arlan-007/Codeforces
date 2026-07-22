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
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        int val = 1;

        for (int r = 0; r < k; r++) {
            vector<int> pos;
            for (int i = r; i < n; i += k) {
                pos.push_back(i);
            }

            int len = pos.size();
            if (r % 2 == 0) {
                for (int j = 0; j < len; ++j) {
                    p[pos[j]] = val++;
                }
            } else {
                for (int j = len - 1; j >= 0; --j) {
                    p[pos[j]] = val++;
                }
            }
        }

        for (int x : p) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}