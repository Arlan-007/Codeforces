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
            int x1 , y1 , x2 , y2;
            cin>>x1>>y1>>x2>>y2;

            int x , y;
            cin>>x>>y;

            bool flag = true;
            int k1 = abs(x1 - x2);
            int k2 = abs(y1 - y2);

            if (k1 % x != 0){
                flag = false;
            }
            if (k2 % y != 0){
                flag = false;
            }

            int a1 = k1 / x;
            int a2 = k2 / y;

            if ((a1 % 2 == 0 && a2 % 2 != 0) || (a1 % 2 != 0 && a2 % 2 == 0)){
                flag = false;
            }

            if (flag){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
    }
    return 0;
}