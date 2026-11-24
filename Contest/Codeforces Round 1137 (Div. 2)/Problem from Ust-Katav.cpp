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
        ll n, ans = 0; cin >> n;
        vector<int> p(n + 2), st{0};
        for (int i = 1; i <= n; i++) cin >> p[i];

        for (int i = 1; i <= n + 1; i++) {
            while (p[st.back()] > p[i]) {
                int j = st.back();
                st.pop_back();
                int L = j - st.back(), R = i - j;
                ans += (min(L, R) == 1 ? max(L, R) : 2);
            }
            st.push_back(i);
        }
        cout << ans << '\n';
    }
}