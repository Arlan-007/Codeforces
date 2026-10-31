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

    ll n, m; cin >> n >> m;
    vector<ll> p;
    for (ll i = 2; i * i <= n; i++) while (n % i == 0) p.push_back(i % m), n /= i;
    if (n > 1) p.push_back(n % m);

    ll l = p.size();
    vector<ll> d((l + 1) * m, -1);
    deque<ll> q{1 % m}; d[1 % m] = 0;

    while (!q.empty()) {
        ll v = q.front(), i = v / m, r = v % m; q.pop_front();
        if (i == l) {
            if (d[r] == -1 || d[r] > d[v] + 1) d[r] = d[v] + 1, q.push_back(r);
        } else {
                ll u = (i + 1) * m + r;
                if (d[u] == -1 || d[u] > d[v]) d[u] = d[v], q.push_front(u);
                u = (i + 1) * m + (r * p[i] % m);
                if (d[u] == -1 || d[u] > d[v]) d[u] = d[v], q.push_front(u);
        }
    }
    for (ll r = 0; r < m; r++) cout << (d[l * m + r] == -1 ? -1 : d[l * m + r] + 1) << '\n';
}