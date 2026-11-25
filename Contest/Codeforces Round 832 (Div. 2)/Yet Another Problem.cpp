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

    int n, q; cin >> n >> q;
    map<int, int> odd, even;
    vector<ll> a(n), prefix(n + 1, 0), last(n + 1, -1), last_xor(n + 1, -1);

    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            cin >> a[i - 1];
            prefix[i] = prefix[i - 1] ^ a[i - 1];
            last[i] = a[i - 1] == 0 ? last[i - 1] : i - 1;
        }

        if (i % 2 == 0) {
            if (odd.count(prefix[i])) last_xor[i] = odd[prefix[i]];
            even[prefix[i]] = i;
        } else {
            if (even.count(prefix[i])) last_xor[i] = even[prefix[i]];
            odd[prefix[i]] = i;
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        if (prefix[r] != prefix[l - 1]) {
            cout << "-1\n";
        } else if (last[r] == last[l - 1]) {
            cout << "0\n";
        } else if ((r - l) % 2 == 0 || a[r - 1] == 0 || a[l - 1] == 0) {
            cout << "1\n";
        } else if (last_xor[r] >= l - 1) {
            cout << "2\n";
        } else {
            cout << "-1\n";
        }
    }
}