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
const int MAXN = 200005;
const int MAX_PRIME = 10000005;

ll fact[MAXN], invFact[MAXN];
vector<int> primes;
vector<bool> is_prime(MAX_PRIME + 1, true);

void build_sieve() {
    is_prime[0] = false; is_prime[1] = false;
    for (int i = 3; i * i <= MAX_PRIME; i += 2)
        if (is_prime[i])
            for (int j = i * i; j <= MAX_PRIME; j += i * 2)
                is_prime[j] = false;

    primes.push_back(2);
    for (int i = 3; i <= MAX_PRIME; i += 2)
        if (is_prime[i]) primes.push_back(i);
}

bool match(string s, string t) {
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s.size(); j++)
            if ((s[i] == s[j]) != (t[i] == t[j]))
                return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build_sieve();
    string s; cin >> s;
    int n = s.size();

    for (int p : primes) {
        string t = to_string(p);
        if (t.size() > n) break;
        if (t.size() != n) continue;

        if (match(s, t)) {
            cout << p << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}