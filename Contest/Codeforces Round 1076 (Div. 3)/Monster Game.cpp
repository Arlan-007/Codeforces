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

int need(vector<int> b , int i) {
    int sum = 0;
    for (int j = 0; j < i; j++) {
        sum += b[j];
    }
    return sum;
}

int strike(vector<int> a , int i) {
    int count = 0;
    for (int j = 0; j < a.size(); j++) {
        if (a[j] >= i) count++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<long long> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<long long> pref(n);
        pref[0] = b[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + b[i];
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 0; i < n; ) {
            long long x = a[i];
            int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
            long long k = n - idx;
            int j = upper_bound(pref.begin(), pref.end(), k) - pref.begin() - 1;
            long long levels = (j >= 0 ? j + 1 : 0);
            ans = max(ans, x * levels);
            while (i < n && a[i] == x) i++;
        }
        cout << ans << '\n';
    }
    return 0;
}