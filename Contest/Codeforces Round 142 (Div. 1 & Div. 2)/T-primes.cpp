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

bool isPrime(long long n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPerfectSquare(long long n) {
    if (n < 0) return false;
    long double root = sqrt(static_cast<long double>(n));
    return std::floor(root) == root;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        bool flag = isPerfectSquare(n);
        if (flag) {
            bool prime = isPrime(sqrt(n));
            if (prime) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}