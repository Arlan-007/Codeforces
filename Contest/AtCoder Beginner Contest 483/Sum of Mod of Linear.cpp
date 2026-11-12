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

const int MAXN = 500005, B = sqrt(MAXN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, a, b; cin >> n;
    vector<vector<int>> cnt(B + 1, vector<int>(B + 1));
    vector<long long> ans(MAXN + 1);
    for (int i = 0; i < n; i++) {
        cin >> a >> b; ans[0] += a;
        if (b <= B) cnt[b][(b - a) % b]++;
        else for (int x = b - a; x <= MAXN; x += b) ans[x] -= b;
    }

    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < i; j++) {
            if (!cnt[i][j]) continue;
            for (int k = j ? j : i; k <= MAXN; k += i) ans[k] -= 1LL * i * cnt[i][j];
        }
    }
    for (int i = 1; i <= MAXN; i++) ans[i] += ans[i - 1] + n;

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}