#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

using ll = long long;

int findLevel(ll n, ll m) {
    if (m > n || m <= 0) return -1;

    queue<pair<ll,int>> q;
    unordered_set<ll> visited;

    q.push(make_pair(n, 0));
    visited.insert(n);

    while (!q.empty()) {
        pair<ll,int> p = q.front();
        q.pop();

        ll x = p.first;
        int level = p.second;

        if (x == m) return level;

        ll left  = (x + 1) / 2;  // ceil
        ll right = x / 2;        // floor

        if (left > 0 && !visited.count(left)) {
            visited.insert(left);
            q.push(make_pair(left, level + 1));
        }

        if (right > 0 && !visited.count(right)) {
            visited.insert(right);
            q.push(make_pair(right, level + 1));
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, m;
        cin >> n >> m;
        cout << findLevel(n, m) << "\n";
    }

    return 0;
}