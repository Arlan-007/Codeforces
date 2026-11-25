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

string s; int n, B;
vector<int> dist;

void rebuild(int b) {
    int lo = b * B, hi = min(n, lo + B);
    int mask = 0;

    for (int i = lo; i < hi; i++) mask |= (1 << (s[i] - 'a'));

    dist[b] = mask;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> s >> q;
    n = s.length(); B = sqrt(n);
    int nb = (n + B - 1) / B; dist.assign(nb, 0);
    for (int b = 0; b < nb; b++) rebuild(b);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c; i--;
            s[i] = c; rebuild(i / B);
        } else {
            int l, r; cin >> l >> r; l--; r--;
            int chr = 0;
            int lb = l / B, rb = r / B;

            if (lb == rb) {
                for (int i = l; i <= r; i++)
                    chr |= (1 << (s[i] - 'a'));
            } else {
                for (int i = l; i < (lb + 1) * B && i < n; i++)
                    chr |= (1 << (s[i] - 'a'));

                for (int b = lb + 1; b < rb; b++)
                    chr |= dist[b];

                for (int i = rb * B; i <= r; i++)
                    chr |= (1 << (s[i] - 'a'));
            }
            cout << __builtin_popcount(chr) << "\n";
        }
    }
}