#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")

using ll = long long;
const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool in(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
int solve_type(const string &s, char openb, char closeb) {
    vector<char> st;
    for (char c : s) {
        if (c != openb && c != closeb) continue;

        if (!st.empty() && st.back() == openb && c == closeb) {
            st.pop_back();
        } else {
            st.push_back(c);
        }
    }
    int ops = 0;
    for (size_t i = 0; i < st.size(); i += 2) {
        ops += 1;
    }

    return ops;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int ans = 0;
        ans += solve_type(s, '(', ')');
        ans += solve_type(s, '[', ']');

        cout << ans << "\n";

    }
}