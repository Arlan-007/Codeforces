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
        int n, cnt = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i], cnt += (a[i] & 1);

        if (n == 1) cout << "Moggity" << '\n';
        else if (n == 2) {
            if((a[0] + a[1]) % 2 == 0) cout << "Moggity" << '\n';
            else cout << "Larpity" << '\n';
        }
        else if (cnt % 2 == 0) cout << "Moggity" << '\n';
        else if (n == 3 && cnt == 3) cout << "Larpity" << '\n';
        else cout << "Moggity" << '\n';
    }
}