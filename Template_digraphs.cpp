%:include <iostream>
%:include <vector>
%:include <algorithm>
%:include <cmath>
%:include <string>
%:include <map>
%:include <set>
%:include <stack>
%:include <queue>
%:include <limits>
using namespace std;

%:pragma GCC optimize("O3")
%:pragma GCC optimize("unroll-loops")

using ll = long long;
const ll INF = (ll)4e18;
const int MOD = 1'000'000'007;

ll binpow(ll a, ll b, ll mod = MOD) <%
    ll res = 1;
    while (b) <%
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    %>
    return res;
%>

ll modinv(ll a, ll mod = MOD) <%
    return binpow(a, mod - 2, mod);
%>

int main() <%
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) <%

    %>
%>
