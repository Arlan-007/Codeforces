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
        ll n, k; cin >> n >> k;
        vector<ll> A(k, 0);

        if (k % 2 == 0) {
            int loose = 0;

            for (int bit = 30; bit >= 0; bit--) {
                ll mask = 1LL << bit;
                if (n & mask) {
                    int zero;
                    if (loose < k) {
                        zero = loose;
                        loose++;
                    } else {
                        zero = 0;
                    }

                    for (int i = 0; i < k; ++i) {
                        if (i != zero)
                            A[i] |= mask;
                    }
                } else {
                    int cnt = loose - (loose & 1);
                    for (int i = 0; i < cnt; i++)
                        A[i] |= mask;
                }
            }
        } else {
            for (auto& x : A) x = n;
        }

        for (auto& x : A) cout << x << " ";
        cout << "\n";
    }
}