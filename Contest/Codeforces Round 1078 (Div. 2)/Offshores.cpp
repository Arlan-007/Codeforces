#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static auto _speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll total_chunks = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total_chunks += a[i] / x;
        }
        ll answer = 0;
        for (int i = 0; i < n; i++) {
            ll current = a[i] + (total_chunks - a[i] / x) * y;
            answer = max(answer, current);
        }

        cout << answer << '\n';
    }

    return 0;
}
