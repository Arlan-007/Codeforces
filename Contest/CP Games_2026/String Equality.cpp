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
    cin >> t;
    while (t--) {
        int n, k;
        string a, b;
        cin >> n >> k >> a >> b;
        vector<int> cntA(26, 0), cntB(26, 0);
        for (char c : a) cntA[c - 'a']++;
        for (char c : b) cntB[c - 'a']++;

        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (cntA[i] < cntB[i]) {
                ok = false;
                break;
            }

            int extra = cntA[i] - cntB[i];
            if (extra % k != 0) {
                ok = false;
                break;
            }
            if (i < 25)
                cntA[i + 1] += extra;
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
}