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
        ll k1, k2, k3; cin >> k1 >> k2 >> k3;
        vector<int> k = {k1, k2, k3};
        sort(k.begin(), k.end());

        if (k[0] == 1) {
            cout << "YES\n";
            return 0;
        }
        int count2 = 0;
        for (int x : k) if (x == 2) count2++;
        if (count2 >= 2) {
            cout << "YES\n";
            return 0;
        }
        if (k[0] == 3 && k[1] == 3 && k[2] == 3) {
            cout << "YES\n";
            return 0;
        }
        if (k[0] == 2 && k[1] == 4 && k[2] == 4) {
            cout << "YES\n";
            return 0;
        }
        cout << "NO\n";
    }
}