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
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s, x = "2025", y = "2026"; cin >> s;

        vector<int> nxt[10];
        for (int i = 0; i < n; i++) nxt[s[i] - '0'].push_back(i);

        vector<ll> slope(n + 2), inter(n + 2), good(n + 1);
        for (int l = 0; l < n; l++) {
            int a = l, b = l;
            for (char c : x) {
                auto &v = nxt[c - '0'];
                auto it = lower_bound(v.begin(), v.end(), a);
                if (it == v.end()) {a = -1; break;}
                a = *it;
            }

            for (char c : y) {
                auto &v = nxt[c - '0'];
                auto it = lower_bound(v.begin(), v.end(), b);
                if (it == v.end()) {b = -1; break;}
                b = *it;
            }

            if (a != -1 && (b == -1 || a <= b)) {
                int r = (b == -1 ? n : b) - 1;
                inter[l + 1] += r - a + 1, inter[a + 2] -= r - a + 1;
                slope[a + 2]--, slope[r + 2]++;
                inter[a + 2] += r + 2, inter[r + 2] -= r + 2;
            }
        }

        ll m = 0, c = 0;
        for (int i = 1; i <= n; i++) m += slope[i], c += inter[i], good[i] = i * (n - i + 1) - (m * i + c);
        for (int i = 1; i <= n; i++) cout << good[i] << ' ';
        cout << endl;
    }
}