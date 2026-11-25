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
        int n, k; cin >> n >> k;
        vector<int> a(n + 2), pivots(k + 2);;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> pivots[i];

        a[0] = a[n+1] = a[pivots[1]];
        pivots[k+1] = n+1;

        int A = 0, B = 0;
        for (int i = 0; i <= k; i++) {
            int cnt = 0;
            for (int j = pivots[i]; j < pivots[i+1]; j++)
                if (a[j] != a[j+1]) cnt++;
            A += cnt;
            B = max(B, cnt);
        }
        
        cout << max(A / 2, B) << "\n";
    }
}