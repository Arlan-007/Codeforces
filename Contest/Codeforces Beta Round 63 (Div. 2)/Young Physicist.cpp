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

int binarySearch(vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    int x,y,z;
    int sum_x=0,sum_y=0,sum_z=0;
    while (t--) {
        cin >> x >> y >> z;
        sum_x += x;
        sum_y += y;
        sum_z += z;
    }
    if (sum_x==0 && sum_y==0 && sum_z==0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}