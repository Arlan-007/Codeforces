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
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, ans = 1; cin >> n;
        while(true) {
            ll curr = 0;
            for(ll i = 1; i <= ans; i++) curr += i * (ans / i);
            if(curr >= n) break;
            ans++;
        }

        vector<ll> a;
        ll f = n, pos = 1;
        for(ll i = ans; i >= 1; i--) {
            ll cont = min(ans / i, f / i);
            for(ll j = 0; j < cont; j++) {
                for(ll k = 0; k < i; k++) a.push_back(pos);
                pos++;
            }
            f -= cont * i;
        }
        cout << ans << endl;
        for(auto &i : a) cout << i << " ";
        cout << endl;
    }
}