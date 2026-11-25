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

int n, q, B, nb;
vector<ll> a, asum;
vector<ll> lazyC, lazyD;

void push(int b) {
    if (lazyC[b] == 0 && lazyD[b] == 0) return;

    int l = b * B, r = min(n, l + B);
    for (int i = l; i < r; i++) a[i] += lazyC[b] + lazyD[b] * i;

    lazyC[b] = 0;
    lazyD[b] = 0;
}

void rebuild(int b) {
    int l = b * B, r = min(n, l + B);
    asum[b] = 0;
    for (int i = l; i < r; i++) asum[b] += a[i];
}

void apply(int b, ll c, ll d) {
    int l = b * B, r = min(n, l + B);
    ll len = r - l;

    lazyC[b] += c; lazyD[b] += d;
    ll sum = 1LL * (l + r - 1) * len / 2;
    asum[b] += c * len + d * sum;
}

void update(int l, int r, ll x, ll d) {
    ll c = x - 1LL * l * d;
    int lb = l / B, rb = r / B;

    if (lb == rb) {
        push(lb);
        for (int i = l; i <= r; i++) a[i] += c + d * i;
        rebuild(lb);
        return;
    }

    push(lb);
    for (int i = l; i < (lb + 1) * B; i++) a[i] += c + d * i;
    rebuild(lb);

    for (int b = lb + 1; b < rb; b++) apply(b, c, d);

    push(rb);
    for (int i = rb * B; i <= r; i++) a[i] += c + d * i;
    rebuild(rb);
}

ll query(int l, int r) {
    int lb = l / B, rb = r / B;

    ll ans = 0;
    if (lb == rb) {
        push(lb);
        for (int i = l; i <= r; i++) ans += a[i];
        rebuild(lb);
        return ans;
    }

    push(lb);
    for (int i = l; i < (lb + 1) * B; i++) ans += a[i];
    rebuild(lb);

    for (int b = lb + 1; b < rb; b++) ans += asum[b];

    push(rb);
    for (int i = rb * B; i <= r; i++) ans += a[i];
    rebuild(rb);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n >> q; a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        B = max(1, (int)sqrt(n)); nb = (n + B - 1) / B;
        asum.assign(nb, 0); lazyC.assign(nb, 0); lazyD.assign(nb, 0);
        for (int b = 0; b < nb; b++) rebuild(b);

        while (q--) {
            int ty; cin >> ty;
            if (ty == 1) {
                ll x, d, l, r; cin >> x >> d >> l >> r; l--; r--;
                update(l, r, x, d);
            }
            else {
                ll l, r; cin >> l >> r; l--; r--;
                cout << query(l, r) << '\n';
            }
        }
    }
}
