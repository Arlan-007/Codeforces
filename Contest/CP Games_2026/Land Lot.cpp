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
    // cin >> t;
    while (t--) {
        int n , m;
        cin>>n>>m;

        vector<vector<int>> mat(n, vector<int>(m));
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                cin>>mat[i][j];
            }
        }

        int a , b;
        cin>>a>>b;

        int cnt1 = INT_MAX;
        int cnt2 = INT_MAX;

        for (int i=0 ; i<max(0 , (n-a+1)) ; i++){
            for (int j=0 ; j<max(0 , (m-b+1)) ; j++){
                int k1 = i;
                int k2 = j;
                int cnt = 0;
                for (int c1 =0 ; c1<a ; c1++){
                    for (int c2 = 0 ; c2 < b ; c2 ++){
                        if (mat[k1 + c1][k2 + c2] == 1){
                            cnt ++;
                        }
                    }
                }
                cnt1 = min(cnt1 , cnt);
            }
        }

        for (int i=0 ; i<max(0 , (n-b+1)) ; i++){
            for (int j=0 ; j<max(0 , (m-a+1)) ; j++){
                int k1 = i;
                int k2 = j;
                int cnt = 0;
                for (int c1 =0 ; c1<b ; c1++){
                    for (int c2 = 0 ; c2 < a ; c2 ++){
                        if (mat[k1 + c1][k2 + c2] == 1){
                            cnt ++;
                        }
                    }
                }
                cnt2 = min(cnt2 , cnt);
            }
        }

        cout<<min(cnt1 , cnt2)<<endl;

    }

    return 0;
}