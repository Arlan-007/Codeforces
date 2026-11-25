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
const int N = 1000005;

struct Node {
    int value, id;
} a[N], temp[N];

ll L[N], R[N];

void cdq(int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    cdq(l, mid);
    cdq(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i].value < a[j].value) {
            R[a[i].id] += j - mid - 1;
            temp[k++] = a[i++];
        } else {
            L[a[j].id] += mid - i + 1;
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        R[a[i].id] += r - mid;
        temp[k++] = a[i++];
    }

    while (j <= r)
        temp[k++] = a[j++];

    for (int x = l; x <= r; ++x)
        a[x] = temp[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i].value;
        a[i].id = i;
    }

    cdq(1, n);

    ll answer = 0;
    for (int i = 1; i <= n; ++i) answer += L[i] * R[i];
    cout << answer << '\n';
}