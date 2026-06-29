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
        int n, q;
        cin >> n >> q;

        vector<ll> a(n+2), b(n+2), c(n+2), best(n+2), pref(n+2);

        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];

        for(int i=1;i<=n;i++){
            c[i] = max(a[i], b[i]);
        }

        best[n] = c[n];
        for(int i=n-1;i>=1;i--){
            best[i] = max(best[i+1], c[i]);
        }

        pref[0] = 0;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + best[i];
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            cout << (pref[r] - pref[l-1]) << " ";
        }
        cout << "\n";
    }
    return 0;
}