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

int highestPowerOfTwo(int x) {
    int p = 1;
    while ((p << 1) <= x) p <<= 1;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        p[n] = 1;
        vector<bool> used(n+1,false);
        for(int i = 2; i<n ; i++){
            p[i] = 1^i;
            used[p[i]] = true;
        }
        for(int i = 2; i<=n ; i++) if(!used[i]) p[1] = i;
        for(int i = 1; i<=n ; i++) cout << p[i] << " ";
        cout << endl;
    }
}

