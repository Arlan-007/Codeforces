#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static auto _speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<string> strips(k);
        for (int i = 0; i < k; i++) {
            cin >> strips[i];
        }
        // Precompute bitmask
        vector<int> mask(n, 0);
        for (int pos = 0; pos < n; pos++) {
            for (int i = 0; i < k; i++) {
                mask[pos] |= 1 << (strips[i][pos] - 'a');
            }
        }
        // Divisor
        vector<int> divisors;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);
                if (d * d != n) divisors.push_back(n / d);
            }
        }
        sort(divisors.begin(), divisors.end());
        for (int d : divisors) {
            bool ok = true;
            vector<int> chosen(d);
            for (int r = 0; r < d && ok; r++) {
                int common = (1 << 26) - 1;
                for (int pos = r; pos < n; pos += d) {
                    common &= mask[pos];
                    if (common == 0) break;
                }
                if (common == 0) {
                    ok = false;
                } else {
                    chosen[r] = __builtin_ctz(common);
                }
            }
            if (!ok) continue;
            string result(n, 'a');
            for (int i = 0; i < n; i++) {
                result[i] = char('a' + chosen[i % d]);
            }
            cout << result << '\n';
            break;
        }
    }

    return 0;
}