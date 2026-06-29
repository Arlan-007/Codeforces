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
    int t ;
    cin >> t ;
    while(t--){
        int n, q ;
        cin >> n >> q ;
        vector <ll> arr1(n+2,0) , pref(n+2);
        vector <ll> arr2(n+2,0);
        vector <ll> arr3(n+2,0);
        for(int i=1; i<=n; i++)cin>>arr1[i];
        for(int i=1; i<=n; i++)cin>>arr2[i];
        for(int i=1; i<=n; i++){
            arr3[i] = max(arr1[i],arr2[i]);
        }
        for(int i=n; i>=1; i--) {
            arr3[i] = max(arr3[i+1],arr3[i]);
        }
        pref[0] = 0;
        for(int i=1;i<=n;i++){
            pref[i] = pref[i-1] + arr3[i];
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            cout << (pref[r] - pref[l-1]) << " ";
        }
        cout << "\n";
    }
}