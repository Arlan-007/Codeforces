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
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        map<ll,ll> freq;
        for (int i = 0; i < n; i++) { ll a; cin >> a; freq[a]++; }

        ll maxx = 0, count = 0;
        while (!freq.empty()) {
            auto [val, cnt] = *freq.begin();

            freq.erase(freq.begin());
            if (cnt & 1) {
                count++;
                maxx = val;
            }
            if (cnt / 2) freq[val + 1] += cnt / 2;
        }
        cout << maxx - count + 1 << "\n";
    }
}