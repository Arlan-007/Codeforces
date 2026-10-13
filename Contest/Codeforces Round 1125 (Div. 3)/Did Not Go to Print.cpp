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
        int n; cin >> n;
        string s; cin >> s;
        stack<int> st;
        vector<bool> a(n + 1, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') st.push(i + 1);
            else if (s[i] == '2') {
                int num;
                if (st.empty()) num = i + 1;
                else num = st.top(), st.pop();
                a[num] = true;
            } else a[i + 1] = true;
        }

        vector<int> left;
        for (int i = 1; i <= n; i++) if (!a[i]) left.push_back(i);
        cout << left.size() << "\n";
        for (size_t i = 0; i < left.size(); i++) cout << left[i] << " ";
        cout << "\n";
    }
}