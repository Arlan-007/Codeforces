#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        int n;
        cin >> n;
        if (n<4) cout << n << endl;
        else {
            n = n%4;
            switch (n) {
                case 0:
                    cout << 0 << endl;
                    break;
                case 1:
                    cout << 1 << endl;
                    break;
                case 2:
                    cout << 0 << endl;
                    break;
                case 3:
                    cout << 1 << endl;
                    break;
                default:
                    cout << 0 << endl;
            }
        }
    }
    return 0;
}