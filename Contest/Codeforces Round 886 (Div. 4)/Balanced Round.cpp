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
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        vector<int> ans(n-1,0);
        for (int i = 1; i < n; i++) {
            ans[i-1] = arr[i] - arr[i-1];
        }
        int consec = 0;
        int curr = consec;
        for (int i = 1; i < n; i++) {
            if (ans[i-1] <= k) curr++;
            else if (curr > consec) {
                consec = curr;
                curr = 0;
            } else curr = 0;
        }
        if (consec == 0 || curr > consec) consec = curr;
        cout << n-consec-1 << endl;
    }
    return 0;
}