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
const int MAX_PRIME = 200005;

vector<bool> is_prime(MAX_PRIME + 1, true);

void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 3; i * i <= MAX_PRIME; i++)
        if (is_prime[i]) for (int j = i * i; j <= MAX_PRIME; j += i * 2) is_prime[j] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    build_sieve();
    while (t--) {
        int n, x; cin >> n;
        while (n--) {
            cin >> x;
            while (!is_prime[x] || !(x & 1)) x++;
            cout << x << ' ';
        }
        cout << '\n';
    }
}