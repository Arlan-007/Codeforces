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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        ll Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;
        vector<ll> x(n), y(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> y[i];
        vector<pair<ll,ll>> a(n);
        for(int i = 0; i < n; i++)
            a[i] = {x[i], y[i]};
        sort(a.begin(), a.end());
        vector<pair<ll,ll>> seg;
        for(int i = 0; i < n; ){
            int j = i;
            ll lo = a[i].second;
            ll hi = a[i].second;
            while(j < n && a[j].first == a[i].first){
                lo = min(lo, a[j].second);
                hi = max(hi, a[j].second);
                j++;
            }
            seg.push_back({lo, hi});
            i = j;
        }
        int m = seg.size();
        const ll INF = LLONG_MAX / 4;
        vector<array<ll,2>> dp(m, {INF, INF});
        ll lo = seg[0].first;
        ll hi = seg[0].second;
        ll len = hi - lo;
        dp[0][0] = llabs(Ay - hi) + len;
        dp[0][1] = llabs(Ay - lo) + len;
        for(int i = 1; i < m; i++){
            ll plo = seg[i-1].first;
            ll phi = seg[i-1].second;
            lo = seg[i].first;
            hi = seg[i].second;
            len = hi - lo;
            dp[i][0] = min(
                dp[i-1][0] + llabs(plo - hi) + len,
                dp[i-1][1] + llabs(phi - hi) + len
            );
            dp[i][1] = min(
                dp[i-1][0] + llabs(plo - lo) + len,
                dp[i-1][1] + llabs(phi - lo) + len
            );
        }
        lo = seg.back().first;
        hi = seg.back().second;
        ll vertical = min(
            dp[m-1][0] + llabs(lo - By),
            dp[m-1][1] + llabs(hi - By)
        );
        ll horizontal = Bx - Ax;
        cout << vertical + horizontal << "\n";
    }
    return 0;
}