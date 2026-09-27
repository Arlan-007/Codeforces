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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;
const int MAXN = 1e5 + 5;

int n, q, a[MAXN], ans[MAXN], arr[MAXN * 696];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());

        ans[0] = a[n - 1] - a[0];
        int z = 0;
        while (a[n - 1]) {
            z++; int ptr = 0;
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j <= i + 696; j++)
                    arr[ptr++] = a[i] ^ a[j];

            nth_element(arr, arr + n - 1, arr + ptr);
            for (int i = 0; i < n; ++i) a[i] = arr[i];
            sort(a.begin(), a.end());
            ans[z] = a[n - 1] - a[0];
        }

        while (q--) {
            int x; cin >> x;
            cout << (x <= z ? ans[x] : 0) << '\n';
        }
    }
}