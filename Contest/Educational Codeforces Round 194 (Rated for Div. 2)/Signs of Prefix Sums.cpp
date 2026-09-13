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

bool can(string s, int val) {
    for (int l = 0; l < s.size();) {
        if (s[l] == '0') {
            l++;
            continue;
        }

        int r = l;
        while (r < s.size() && s[r] != '0') r++;

        vector<int> len;
        for (int i = l; i < r;) {
            int j = i;
            while (j < r && s[j] == s[i]) j++;
            len.push_back(j - i);
            i = j;
        }

        if (val == 1) {
            if (len.size() > 1) return false;
            if (r < s.size() && len[0] % 2 == 0) return false;
        }
        else if (val == 2) {
            for (int i = 1; i + 1 < len.size(); i++)
                if (len[i] == 2) return false;
        }
        else return true;
        l = r;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (s[0] == '0' || s.find("00") != string::npos) {
            cout << "-1" << endl;
            continue;
        }

        if (can(s, 1)) cout << "1" << endl;
        else if (can(s, 2)) cout << "2" << endl;
        else cout << "3" << endl;
    }
}