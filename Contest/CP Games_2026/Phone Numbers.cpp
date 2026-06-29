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

    int T = 1;
    // cin >> t;
    while (T--) {
        int n; cin >> n;
        vector<string> names(n);
        vector<int> taxi(n, 0);
        vector<int> pizza(n, 0);
        vector<int> girl(n, 0);
        int max_taxi = 0, max_pizza = 0, max_girl = 0;
        for (int i = 0; i < n; ++i) {
            int count;
            cin >> count >> names[i];
        
            for (int j = 0; j < count; ++j) {
                string num;
                cin >> num;
                string nums = "";
                for (char c : num) if (c != '-') nums += c;
                bool taxi_ = true;
                bool pizza_ = true;
                for (int k = 1; k < 6; ++k) {
                    if (nums[k] != nums[0]) taxi_ = false;
                    if (nums[k] >= nums[k - 1]) pizza_ = false;
                }
                if (taxi_) taxi[i]++;
                else if (pizza_) pizza[i]++;
                else girl[i]++;
            }
            max_taxi = max(max_taxi, taxi[i]);
            max_pizza = max(max_pizza, pizza[i]);
            max_girl = max(max_girl, girl[i]);
        }

        vector<string> best_taxi, best_pizza, best_girl;
        for (int i = 0; i < n; ++i) {
            if (taxi[i] == max_taxi) best_taxi.push_back(names[i]);
            if (pizza[i] == max_pizza) best_pizza.push_back(names[i]);
            if (girl[i] == max_girl) best_girl.push_back(names[i]);
        }

        cout << "If you want to call a taxi, you should call: ";
        for (int i = 0; i < best_taxi.size(); ++i) cout << best_taxi[i] << (i + 1 == best_taxi.size() ? "" : ", ");
        cout << "." << endl;
        cout << "If you want to order a pizza, you should call: ";
        for (int i = 0; i < best_pizza.size(); ++i) cout << best_pizza[i] << (i + 1 == best_pizza.size() ? "" : ", ");
        cout << "." << endl;
        cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
        for (int i = 0; i < best_girl.size(); ++i) cout << best_girl[i] << (i + 1 == best_girl.size() ? "" : ", ");
        cout << "." << endl;
    }
}