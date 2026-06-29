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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string S;
        cin >> S;

        vector<int> freq(26, 0);
        for (char c : S) freq[c - 'a']++;

        int best_k = 1;
        int min_ops = N;

        for (int k = 1; k <= 26; k++) {
            if (N % k != 0) continue;

            int target = N / k;
            vector<int> f = freq;
            sort(f.rbegin(), f.rend());

            int kept = 0;
            for (int i = 0; i < k; i++) {
                kept += min(f[i], target);
            }

            int ops = N - kept;
            if (ops < min_ops) {
                min_ops = ops;
                best_k = k;
            }
        }

        int target = N / best_k;
        vector<pair<int, int>> chars;
        for (int i = 0; i < 26; i++) {
            chars.push_back({freq[i], i});
        }
        sort(chars.rbegin(), chars.rend());
        vector<int> need(26, 0);

        for (int i = 0; i < best_k; i++) {
            need[chars[i].second] = target;
        }

        string result = S;

        vector<int> used(26, 0);
        for (int i = 0; i < N; i++) {
            int c = result[i] - 'a';
            if (need[c] > 0 && used[c] < need[c]) {
                used[c]++;
            } else {
                result[i] = '?';
            }
        }

        int ptr = 0;
        for (int i = 0; i < N; i++) {
            if (result[i] == '?') {
                while (used[ptr] >= need[ptr]) ptr++;
                result[i] = char('a' + ptr);
                used[ptr]++;
            }
        }

        cout << min_ops << "\n";
        cout << result << "\n";
    }

    return 0;
}