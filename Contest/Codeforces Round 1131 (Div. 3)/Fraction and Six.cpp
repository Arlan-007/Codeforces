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
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string p, q; cin >> p >> q;
        vector<int> cnt(26);
        for (char c : p) cnt[c - 'a']++;
        for (char c : q) cnt[c - 'a']--;

        bool pos = cnt['s' - 'a'] == 1 && cnt['i' - 'a'] == 1 && cnt['x' - 'a'] == 1;
        for (int i = 0; i < 26; i++) if (i != 's' - 'a' && i != 'i' - 'a' && i != 'x' - 'a' && cnt[i] != 0) pos = false;
        cout << (pos ? "YES" : "NO") << '\n';
    }
}