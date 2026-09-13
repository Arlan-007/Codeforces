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

#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,lzcnt,bmi2,bmi,tune=native")

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
        int n; cin >> n;
        vector<int> a(n), one, zero;
        for (int& x : a) cin >> x;
        string s; cin >> s;

        ll inv = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) cnt1++;
            else one.push_back(cnt1), inv += cnt1;
        }

        cnt1 = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!a[i]) cnt1++;
            else zero.push_back(cnt1);
        }

        cout << inv << ' ';
        vector<int> cnt(2,0);
        for (char c : s) {
            if (inv == 0) {
                cout << 0 << ' ';
                continue;
            }
            if (c == '1') {
                if (!zero.empty()) {
                    inv -= max(zero.back() - cnt[1], 0);
                    zero.pop_back(); cnt[0]++;
                }
            } else {
                if (!one.empty()) {
                    inv -= max(one.back() - cnt[0],0);
                    one.pop_back(); cnt[1]++;
                }
            }
            cout << inv << ' ';
        }
        cout << "\n";
    }
}