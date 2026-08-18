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
        ll a, b; cin >> a >> b;

        ll n = 0;
        while ((n+1)*(n+2)/2 <= a+b) n++;

        ll rem = min(a, n*(n+1)/2);
        vector<ll> day1, day2;
        for (ll i = n; i >= 1; i--) {
            if (i <= rem) {
                day1.push_back(i);
                rem -= i;
            }
            else day2.push_back(i);
        }

        cout << day1.size() << endl;
        for (ll x : day1) cout << " " << x; cout << "\n";
        cout << day2.size() << endl;
        for (ll x : day2) cout << " " << x; cout << "\n";

    }
}