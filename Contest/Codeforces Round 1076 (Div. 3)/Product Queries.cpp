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

static const int INF = 1e9;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> occ(n+1,0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            occ[x]++;
        }
        vector<int> val(n + 1, INF);
        for (int x = 1; x <= n; x++) {
            if (occ[x] > 0) {
                val[x] = 1;
            }
        }
        for (int j = 1; j <= n; j++) {
            if (val[j] == INF) continue;
            for (int k = 1; j * k <= n; k++) {
                if (occ[k] == 0) continue;
                int prod = j * k;
                val[prod] = min(val[prod], val[j] + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (val[i] == INF) cout << -1;
            else cout << val[i];
            if (i < n) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}