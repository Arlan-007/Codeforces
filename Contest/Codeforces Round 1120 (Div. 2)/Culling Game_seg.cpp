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

struct SGtree {
    int size;
    vector<ll> seg_tree;
    vector<ll> need_tree;

    SGtree(int n) {
        size = n;
        seg_tree.resize(4 * n);
        need_tree.resize(4 * n);
    }

    void build(vector<ll> &a, int x, int lx, int rx) {
        if (lx == rx) {
            seg_tree[x] = a[lx];
            need_tree[x] = a[lx];
            return;
        }

        int m = (lx + rx) >> 1;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m+1, rx);

        ll leftSum = seg_tree[2*x+1];
        ll rightNeed = need_tree[2*x+2];

        seg_tree[x] = leftSum + seg_tree[2*x+2];
        need_tree[x] = max(
            need_tree[2*x+1],
            rightNeed - leftSum
        );
    }

    void build(vector<ll> &a) {
        build(a, 0, 0, size-1);
    }


    void set(int i, int ind, int left, int right, ll val) {
        if (left == right) {
            seg_tree[i] = val;
            need_tree[i] = val;
            return;
        }

        int m = (left + right) >> 1;
        if (ind <= m) set(2*i+1, ind, left, m, val);
        else set(2*i+2, ind, m+1, right, val);

        ll leftSum = seg_tree[2*i+1];
        ll rightNeed = need_tree[2*i+2];

        seg_tree[i] =
            seg_tree[2*i+1] +
            seg_tree[2*i+2];

        need_tree[i] = max(
            need_tree[2*i+1],
            rightNeed - leftSum
        );
    }

    void set(int ind, ll val) {
        set(0, ind, 0, size-1, val);
    }

    int loss(int i, int left, int right, int pos, ll &cur) {
        if (right < pos) return -1;
        if (left >= pos) {
            if (cur >= need_tree[i]) {
                cur += seg_tree[i];
                return -1;
            }
        }

        if (left == right) return left;

        int m = (left + right) >> 1;
        int ans = loss(2*i+1, left, m, pos, cur);

        if (ans != -1) return ans;

        return loss(2*i+2, m+1, right, pos,cur);
    }

    int loss(int pos, ll &cur) {
        return loss(
            0, 0, size-1, pos, cur
        );
    }


    ll query(int i, int left, int right, int lx, int rx) {
        if (left > rx || right < lx) return 0;
        if (left >= lx && right <= rx) return seg_tree[i];

        int m = (left + right) >> 1;
        return query(2*i+1, left, m, lx, rx) + query(2*i+2, m+1, right, lx, rx);
    }

    ll query(int lx, int rx) {
        if (lx > rx) return 0;
        return query(0, 0, size-1, lx, rx);
    }


    int win(int i, int left, int right) {
        if (seg_tree[i] == 0) return -1;
        if (left == right) return left;

        int m = (left + right) >> 1;
        int ans = win(2*i+1, left, m);
        if (ans != -1)return ans;
        return win(2*i+2, m+1, right);
    }

    int win() {
        return win(0, 0, size-1);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n), p(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

        SGtree st(n);
        st.build(a);

        vector<ll> ans(n);
        auto solve = [&]() -> ll {
            int champ = st.win();
            
            ll skill = a[champ];
            ll los = 0;
            while (true) {
                int nxt = st.loss(champ + 1, skill);
                if (nxt == -1) break;

                los++; champ = nxt;
                skill = a[champ];
            }
            return los;
        };


        ans[0] = solve();
        for (int i = 0; i < n-1; i++) {
            st.set(p[i], 0);
            ans[i+1] = solve();
        }

        for (int i = 0; i < n; i++)cout << ans[i] << ' ';
        cout << '\n';
    }
}
