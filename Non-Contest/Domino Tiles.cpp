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

        int ans = 0;
        vector<string> valid = {"0011" , "0110" , "1100" , "1001"};

        for (int j = 0; j < 4; j++) {
            bool pos = true;
            for (int i = 0; i < n; i++) {
                if(s[i] != '?' && s[i] != valid[j][i % 4]){
                    pos = false;
                    break;
                }
            }
            if(pos) ans++;
        }

        cout << ans << "\n";
    }
}