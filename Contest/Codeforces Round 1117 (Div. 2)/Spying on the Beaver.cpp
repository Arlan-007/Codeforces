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
        int n, m; cin >> n;
        vector<ll> p(n+1 , 0);
        for (int i = 2; i <= n; i++) cin >> p[i];
        cin >> m;
        vector<ll> a(m+1 , 0) , flg(n+1,0) , cam;
        for (int i = 0; i < m; i++) {cin >> a[i]; flg[a[i]] = 1;}

        for (int i = n; i >= 2; i--) {
            int par = p[i];
            if (flg[par] && flg[i]) cam.push_back(i);
            else flg[par] |= flg[i];
        }

        cout << cam.size();
        for (int x : cam) {
            cout << " " << x;
        }
        cout << "\n";




    }
}