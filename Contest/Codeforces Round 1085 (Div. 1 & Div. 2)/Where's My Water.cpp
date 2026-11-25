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
        ll n, h, ptr; cin >> n >> h;
        vector<ll> a(n), val(n);;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            ptr = a[i];
            for (int j = i; j < n; j++) ptr = max(ptr, a[j]), val[i] += h - ptr;
            ptr = a[i];
            for (int j = i-1; j >= 0; j--) ptr = max(ptr, a[j]), val[i] += h - ptr;
        }

        ll bianca = 0;
        for (int i = 0; i < n; i++) {
            ptr = i;
            for (int j = i; j < n; j++) {
                if (a[j] > a[ptr]) ptr = j;
                bianca = max(val[i] + val[j] - val[ptr],bianca);
            }
        }
        cout << bianca << "\n";
    }
}