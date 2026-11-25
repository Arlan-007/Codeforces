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

    int lim = 31623;
    vector<int> spf(lim + 1, 0);

    for (int i = 2; i <= lim; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            if (1LL * i * i <= lim) {
                for (int j = i * i; j <= lim; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (spf[i] == i) {
            primes.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> seen;
        bool flg = false;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if (flg) continue;
            for (int p : primes) {
                if (1LL * p * p > x) break;

                if (x % p == 0) {
                    if (!seen.insert(p).second) {
                        flg = true;
                    }
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }
            if (x > 1 && !seen.insert(x).second) {
                flg = true;
            }
        }
        cout << (flg ? "YES\n" : "NO\n");
    }
}