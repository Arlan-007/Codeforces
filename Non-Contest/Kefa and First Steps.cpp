#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

static auto _speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

using ll = long long;
using ld = long double;

template<class T>
using vec = vector<T>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll INF = (ll) 4e18;
const int MOD = 1'000'000'007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    vector<int> V(t+2);
    V[0] = 0;
    V.back() = 10000;
    for (int i = 0; i < t; i++) {
        cin >> V[i];
    }
    int counter = 0;
    vector<int> ans;
    for (int i = 1; i < t+2; i++) {
        if (V[i - 1] <= V[i]) {
            counter++;
            if (i == t+1) {
                ans.push_back(counter);
            }
        } else {
            counter++;
            ans.push_back(counter);
            counter = 0;
        }
    }
    int max = 0;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] > max) {
            max = ans[i];
        }
    }
    // if (t == 1) {
    //     cout << 1 << '\n';
    // }else if (max == 1) {
    //     cout << 0 << '\n';
    // }else {
    //     cout << max << '\n';
    // }
    cout << max << endl;
    return 0;
}