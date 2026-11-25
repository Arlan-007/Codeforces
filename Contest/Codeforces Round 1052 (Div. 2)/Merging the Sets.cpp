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

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m, 0);
        int t = 0;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            v[i].resize(l);
            for (int j = 0; j < l; j++) {
                int x;
                cin >> x;
                x--;
                if (cnt[x] == 0) t++;
                cnt[x]++;
                v[i][j] = x;
            }
        }
        int ans = 0;
        if (t==m) ans = 1;
        for (int i = 0; i < n; i++) {
            for (int x : v[i]) {
                cnt[x]--;
                if (cnt[x] == 0) t--;
            }
            if (t == m) ans++;
            for (int x : v[i]) {
                if (cnt[x] == 0) t++;
                cnt[x]++;
            }
        }
        cout << (ans >= 3 ? "YES\n" : "NO\n");
    }

    return 0;
}