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
        int n; cin >> n;
        if (n == 1) {cout << "1" << "\n"; continue;}
        if (n == 2) {cout << "11" << "\n"; continue;}

        int q = (n + 1) / 3, r = (n + 1) % 3;
        int a = q, b = q, c = q;
        string kedar(n, '0');

        if (r == 0 && q % 2 == 1) {
            kedar[q - 1] = '1';
            kedar[q + 1] = '1';
            kedar[2 * q + 1] = '1';
        }
        else {
            int a = q, b = q;
            if (q % 2 == 0) a++;
            else b++;

            kedar[a - 1] = '1';
            kedar[a + b - 1] = '1';
        }
        cout << kedar << '\n';
    }
}