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
    // cin >> t;
    while (t--) {
        char pos;
        cin >> pos;
        string s;
        cin >> s;
        string ans = "qwertyuiopasdfghjkl;zxcvbnm,./";
        if (pos == 'R') {
            for (int i = 0; i < s.size(); i++) {
                s[i] = ans[ans.find(s[i])-1];
            }
            cout << s << endl;
        } else if (pos == 'L') {
            for (int i = 0; i < s.size(); i++) {
                s[i] = ans[ans.find(s[i])+1];
            }
            cout << s << endl;
        }
    }
    return 0;
}