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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int k; cin >> k;
    string s = "(n/n)";
    for(int j = k - 1; j >= 0; j--){
        string temp = "(n";
        for(int i = 0; i < j; i ++) temp += "-n/n";
        temp += ")";
        s = "(n/n-" + temp + "*" + s + ")";
    }
    string base = "(n/n-(n/n+n/n)*(n-(n/n+n/n)*round((n-n/n)/(n/n+n/n))))";
    cout << base << "*" << s << "\n";
}