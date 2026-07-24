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
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        int i = 0;
        while (k > 0) {
            while (i + 1 < n && !(s[i] == '4' && s[i + 1] == '7')) i++;
            if (i + 1 >= n) break;
            k--;

            if ((i + 1) % 2 == 1) {
                s[i + 1] = '4';
                if (i + 2 < n && s[i + 2] == '7') {
                    if (k % 2 == 1)
                        s[i + 1] = '7';
                    break;
                }
            } else {
                s[i] = '7';
                if (i > 0 && s[i - 1] == '4') {
                    if (k % 2 == 1)
                        s[i + 1] = '4';
                    break;
                }
            }
        }
        cout << s << '\n';

    }
}