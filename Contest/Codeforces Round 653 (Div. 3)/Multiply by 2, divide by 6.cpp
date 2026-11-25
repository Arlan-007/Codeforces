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

void primeFactorization(int n , vector<int>& v) {
    while (n % 2 == 0) {
        v[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            v[i]++;
            n /= i;
        }
    }
    if (n > 2) {
        v[n]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int counter2 = 0 , counter3 = 0;
        while (n%2 == 0) {
            counter2++;
            n /= 2;
        }
        while (n%3 == 0) {
            counter3++;
            n /= 3;
        }
        if (n!=1 || counter3-counter2 < 0) cout << -1 << '\n';
        else cout << 2*counter3 - counter2  << '\n';
    }
    return 0;
}