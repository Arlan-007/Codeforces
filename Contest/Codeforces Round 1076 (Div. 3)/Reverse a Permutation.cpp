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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(a);
        sort(b.rbegin(), b.rend());
        auto mismatch_pair = mismatch(a.begin(), a.end(), b.begin(), b.end());
        if (mismatch_pair.first != a.end()) {
            int index = distance(a.begin(), mismatch_pair.first);
            int idx = max_element(a.begin() + index, a.end()) - a.begin();
            reverse(a.begin() + index, a.begin() + idx + 1);
            for (int i = 0; i < n; i++) cout << a[i] << " ";
        } else for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}