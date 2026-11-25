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
        int n;
        cin >> n;

        vector<int> a(n);

        int low = 1, high = n;
        int idx = n - 1;

        while (low <= high) {
            a[idx--] = high--;
            if (low <= high) {
                a[idx--] = low++;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}