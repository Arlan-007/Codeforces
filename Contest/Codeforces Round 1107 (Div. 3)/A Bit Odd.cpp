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
        string s; cin >> s;

        bool BoolSheet = 0;
        int l = 0, r = n - 1;
        while(l < n && s[l] == '0') l++;
        while(r >= 0 && s[r] == '1') r--;
        if (l > r) {
            cout << "Bob" << '\n';
            continue;
        }

        int cnt = 1;
        for(int i = l; i < r; i++){
            if(s[i + 1] == s[i]) cnt++;
            else{
                if(cnt % 2 == 1) BoolSheet = true;
                cnt = 1;
            }
        }

        if(cnt % 2 == 1) BoolSheet = true;
        cout << (BoolSheet ? "Alice" : "Bob") << '\n';
    }
}