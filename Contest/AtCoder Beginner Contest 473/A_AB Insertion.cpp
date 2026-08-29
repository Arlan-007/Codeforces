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

const int INF = 1e9;
const int NEG = -INF;
const int MOD = 1'000'000'007;


int n, B;
vector<int> a, bsum, bmin;

void rebuild(int b) {
    int lo = b * B, hi = min(n, lo + B);
    int s = 0, m = INF;

    for (int i = lo; i < hi; i++) {
        s += a[i];
        m = min(m, s);
    }
    bsum[b] = s; bmin[b] = m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; string s;
    cin >> n >> s >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) a[i] = (s[i] == 'A' ? 1 : -1);

    B = sqrt(n);
    int nb = (n + B - 1) / B;
    bsum.assign(nb, 0); bmin.assign(nb, INF);
    for (int b = 0; b < nb; b++) rebuild(b);

    string out;
    while (q--) {
        int t; cin >> t;

        if (t == 1) {
            int i; char c; cin >> i >> c; i--;
            a[i] = (c == 'A' ? 1 : -1);
            rebuild(i / B);
        } else {
            int l, r; cin >> l >> r; l--; r--;
            int S = 0, M = INF, bl = l / B, br = r / B;

            if (bl == br) {
                for (int i = l; i <= r; i++) {
                    M = min(M, S + a[i]);
                    S += a[i];
                }
            } else {
                for (int i = l; i < (bl+1)*B; i++) {
                    M = min(M, S + a[i]);
                    S += a[i];
                }
                for (int b = bl+1; b < br; b++) {
                    M = min(M, S + bmin[b]);
                    S += bsum[b];
                }
                for (int i = br*B; i <= r; i++) {
                    M = min(M, S + a[i]);
                    S += a[i];
                }
            }
            out += (M >= 0 ? "Yes\n" : "No\n");
        }
    }
    cout << out;
}
