#include <algorithm>
#include<iostream>
#include <map>
#include <vector>
using namespace std;
const int MAXN = 200000;
long long fact[MAXN+1], invFact[MAXN+1];
typedef long long ll;
const int MOD = 1e9 + 7;

ll power(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;

    ll num = 1, den = 1;
    for (int i = 0; i < r; i++) {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }

    return (num * modInverse(den)) % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<long long> v(n);
    map<long long,int> m;
    for(int i=0;i<n;i++) {
        cin>>v[i];
        m[v[i]]++;
    }
    vector<int> a;
    for (auto it = m.begin(); it != m.end(); it++) {
        a.push_back(it->second);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i=a.size()-1;i>=1;i--) {
        for (int j=i-1;j>=0;j--) {
            if (a[i]+a[j]<k) break;
            ans = (ans + nCr(a[i]+a[j],k)) % MOD;
            ans = (ans - nCr(a[i],k) + MOD) % MOD;
            ans = (ans - nCr(a[j],k) + MOD) % MOD;
        }
        if (a[i]+a[i-1]<k) break;
    }
    cout<<ans<<'\n';
}