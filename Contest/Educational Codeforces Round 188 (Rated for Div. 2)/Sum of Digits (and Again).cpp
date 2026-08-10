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

ll digit_sum(string n) {
    ll sum = 0;
    for (char x : n)
        sum += x - '0';
    return sum;
}

string build (ll num) {
    string s = to_string(num);
    while (num > 9) {
        num = digit_sum(to_string(num));
        s += to_string(num);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;

        int n = s.size();
        if(n == 1){
            cout << s << "\n";
            continue;
        }

        vector<int> freq_(10,0);
        for (char c : s) freq_[c - '0']++;
        int total = 0;
        for (char c : s) total += c - '0';

        for(int i = 1; i <= n * 9; i++) {
            string end = build(i);
            if (end.size() >= n) continue;

            int end_sum = 0;
            for (char c : end) end_sum += c - '0';
            if (total - end_sum != i) continue;

            vector<int> freq(freq_);
            bool ok = true;
            for (char c : end)
                if (freq[c - '0']-- <= 0) { ok = false; break; }
            if (!ok) continue;

            string left;
            for (int d = 0; d <= 9; d++)
                left += string(freq[d], '0' + d);

            int idx = left.find_first_not_of('0');
            if (idx == string::npos) continue;
            if (idx != 0) swap(left[0], left[idx]);

            cout << left + end << endl;
            break;
        }
    }
}