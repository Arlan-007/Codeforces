#include <iostream>
#include <vector>
#include <algorithm>
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
    while (t--) {
        int l, m, n;
        cin >> l >> m >> n;
        int time = min(l, m);
        int lastflip = n%m;
        int flow = time - lastflip;
        if ((n/m)%2 != 0) {
            if (flow < 0) cout << 0 << endl;
            else cout << flow << endl;
        } else {
            if (flow < 0) cout << 0 << endl;
            else cout << l - lastflip << endl;
        }
    }
    return 0;
}