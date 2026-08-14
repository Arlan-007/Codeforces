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
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> pref(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            cout << "? 1 " << i << endl;
            cin >> pref[i];
        }

        ll sec;
        cout << "? 2 3" << endl;
        cin >> sec;

        vector<ll> a(n + 1);
        for (int i = 3; i <= n; i++) a[i] = pref[i] - pref[i - 1];

        a[2] = sec - a[3];
        a[1] = pref[2] - a[2];

        cout << "!";
        for (int i = 1; i <= n; i++) cout << " " << a[i];
        cout << endl;
    }
}