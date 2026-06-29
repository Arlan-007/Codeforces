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
        int n,h,l;
        cin >> n >> h >> l;
        vector<int> A(n);
        int R = 0, C = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x <= h) R++;
            if (x <= l) C++;
        }
        int minRC = min(R, C);
        int maxRC = max(R, C);
        if (minRC - maxRC/2 >= 0) cout << maxRC/2 << endl;
        else cout << minRC << endl;
    }
    return 0;
}