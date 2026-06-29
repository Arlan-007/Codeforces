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
#include <iterator>
#include <climits>
#include <deque>
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

bool can(const vector<ll>& a, const vector<ll>& b,
         const vector<pair<ll,int>>& ord, ll k) {
    int n = a.size();
    vector<ll> val(n);
    vector<int> id(n);
    for(int i = 0; i < n; ++i){
        val[i] = ord[i].first;
        id[i]  = ord[i].second;
    }

    set<int> rem;
    for(int i = 0; i < n; ++i) rem.insert(i);

    while(!rem.empty()){
        int s = *rem.begin();
        rem.erase(s);
        queue<int> q;
        q.push(s);
        vector<int> comp;

        while(!q.empty()){
            int u = q.front(); q.pop();
            comp.push_back(id[u]);

            ll Lval = val[u] - (k - 1);
            ll Rval = val[u] + (k - 1);
            int L = int(lower_bound(val.begin(), val.end(), Lval) - val.begin());
            int R = int(upper_bound(val.begin(), val.end(), Rval) - val.begin()) - 1;

            // take all < L
            auto it = rem.begin();
            while(it != rem.end() && *it < L){
                int v = *it;
                it = rem.erase(it);
                q.push(v);
            }

            // take all > R
            it = rem.upper_bound(R);
            while(it != rem.end()){
                int v = *it;
                it = rem.erase(it);
                q.push(v);
            }
        }

        vector<ll> cur, tar;
        for(int idx : comp){
            cur.push_back(a[idx]);
            tar.push_back(b[idx]);
        }
        sort(cur.begin(), cur.end());
        sort(tar.begin(), tar.end());
        if(cur != tar) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<long long> b = a;
        sort(b.begin(), b.end());

        if (a == b) {
            cout << -1 << '\n';
            continue;
        }

        long long low = *min_element(a.begin(), a.end());
        long long high = *max_element(a.begin(), a.end());
        long long ans = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                long long v = max(a[i] - low, high - a[i]);
                ans = min(ans, v);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
