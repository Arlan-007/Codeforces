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
        string s; cin >> s;
        int n = s.length();

        for (int a = 1; a <= 5; a++) {
            int l = n / a;
            int ext = n % a;
            int b = l + (ext > 0 ? 1 : 0);

            if (b <= 20) {
                cout << a << " " << b << endl;
                int idx = 0;
                for (int i = 0; i < a; i++) {
                    int let = l + (i < ext ? 1 : 0);
                    for (int j = 0; j < let; j++) cout << s[idx++];
                    for (int j = 0; j < b - let; j++) cout << '*';
                    cout << endl;
                }
                break;
            }
        }
    }
}