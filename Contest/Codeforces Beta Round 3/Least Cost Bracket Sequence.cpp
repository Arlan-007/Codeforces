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
        string s;
        cin >> s;

        priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> pq;
        ll cost = 0;
        int bal = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                bal++;
            } else if (s[i] == ')') {
                bal--;
            } else {
                ll open, close;
                cin >> open >> close;
                cost += close;
                bal--;
                pq.push({open - close, i});
            }

            if (bal < 0) {
                if (pq.empty()) {
                    cout << -1 << '\n';
                    return 0;
                }
                auto [extra, pos] = pq.top();
                pq.pop();
                cost += extra;
                s[pos] = '(';
                bal += 2;
            }
        }

        if (bal != 0) {
            cout << -1 << '\n';
        } else {
            cout << cost << '\n' << s << '\n';
        }
    }
}