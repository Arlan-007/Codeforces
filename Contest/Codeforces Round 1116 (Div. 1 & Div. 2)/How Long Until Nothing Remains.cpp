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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        auto check = [&](ll x) {
            priority_queue<int> pq;
            for (int i = 0; i < n; i++) pq.push(a[i]);

            for (int i = x - 1; i >= 0; i--) {
                if(pq.empty()) return true;
                int top = pq.top(); pq.pop();
                if(i <= 30 && top > 1 << i) pq.push(top - (1 << i));
            }
            return pq.empty();
        };

        ll lo = n, hi = n + 30;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}