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
        ll n; cin >> n;
        string s; cin >> s;

        if (n & 1) {
            cout << "-1\n"; continue;
        }

        vector<ll> cnt(26,0);
        for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;

        sort (cnt.begin(), cnt.end());
        if (cnt[25] > (n + 1) / 2) cout << "-1\n";
        else {
            ll count = 0;
            vector<ll> cnt_(26,0);
            for (int i = 0; i < (n + 1) / 2; i++) {
                if (s[i] == s[n - i - 1]) {
                    cnt_[s[i] - 'a']++;
                    count++;
                }
            }
            sort (cnt_.begin(), cnt_.end());
            cout << max(cnt_[25], (count + 1) / 2) << "\n";
        }
    }
}