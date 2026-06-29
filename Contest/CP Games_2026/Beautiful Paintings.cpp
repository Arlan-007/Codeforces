#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <tuple>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <complex>
#include <bitset>
#include <random>
#include <limits>
#include <climits>
#include <cfloat>
#include <cassert>
#include <exception>
#include <stdexcept>

using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

using ll = long long;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        int freq[1000] = {0};
        for (int i=0; i<n ; i++){
            cin>>arr[i];
            freq[arr[i] - 1] ++;
        }
        int cnt = 0;
        int gre[1001] = {0};
        for (int i=1 ; i<=1000 ; i++){
            for (int j=0 ; j<1000 ; j++){
                if (freq[j] >= i){
                    gre[i] ++;
                }
            }
        }
        for (int i=0 ; i<1001 ; i++){
            if (gre[i] > 0){
                cnt += (gre[i] - 1);
            }
        }
        cout<<cnt<<endl;

    }

    return 0;
}