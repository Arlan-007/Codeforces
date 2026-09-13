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
        vector<int> b(n + 1), pos(n + 2);
        for (int i = 1; i <= n; i++) cin >> b[i];

        for (int i = 1; i <= n; i++)
            if(b[i] != -1)
                if(max(1, i + 1 - b[i]) <= min(n,i - 1 + b[i]))
                    pos[max(1, i + 1 - b[i])]++, pos[min(n, i - 1 + b[i]) + 1]--;
        for (int i = 1; i <= n; i++) pos[i] += pos[i - 1];
        for (int i = 1; i <= n; i++) pos[i] = pos[i] > 0 ? 1 : 0;

        int stronger = 0;
        for (int i = 1; i <= n; i++) if(pos[i] == 0) stronger = 1;
        if(!stronger) {
            cout << -1 << endl; goto end;
        }

        for (int i = 1; i <= n; i++)
            if(b[i] != -1) {
                stronger = 0;
                if(i - b[i] >= 1 && pos[i - b[i]] == 0) stronger = 1;
                if(i + b[i] <= n && pos[i + b[i]] == 0) stronger = 1;

                if(!stronger) {
                    cout << -1 << endl; goto end;
                }
            }

        for (int i = 1; i <= n; i++) cout << (pos[i] == 0 ? 1 : 0);
        cout << endl;
        end:;
    }
}