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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        long long h;
        cin >> n >> m >> h;

        vector<long long> original(n), add(n, 0);
        vector<int> last_reset(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> original[i];
        }

        int reset_id = 0;

        for (int i = 0; i < m; i++) {
            int b;
            long long c;
            cin >> b >> c;
            --b;
            if (last_reset[b] != reset_id) {
                add[b] = 0;
                last_reset[b] = reset_id;
            }

            add[b] += c;

            if (original[b] + add[b] > h) {
                reset_id++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (last_reset[i] == reset_id)
                cout << original[i] + add[i];
            else
                cout << original[i];

            cout << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}