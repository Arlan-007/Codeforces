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
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt = 0;
        int cum = n / k;
        for (int i = 0; i < cum; i++) {
            bool flg = false;
            for (int j = 0; j < k; j++) {
                int idx = i * k + j;
                if (s[idx] == '0') {
                    flg = true;
                    break;
                }
            }
            if (!flg) cnt++;
        }
        cout << cnt << "\n";
    }
}