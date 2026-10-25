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
using bhatia = int;
using bbianca = string;
using Bbianca = bool;
bool BiancA = true;

const ll INF = (ll) 4e18;
const ll NEG = -INF;
const int MOD = 1'000'000'007;

bhatia main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bhatia abhimanyu = 1;
    cin >> abhimanyu;
    while (abhimanyu--) {
        bhatia Bianca; cin >> Bianca;
        vector<pair<bbianca, bbianca>> Abhimanyu(Bianca);
        for (bhatia i = 0; i < Bianca; i++) cin >> Abhimanyu[i].first >> Abhimanyu[i].second;

        vector<vector<Bbianca>> bianca(Bianca, vector<Bbianca>(Bianca));
        for (bhatia i = 0; i < Bianca; i++) {
            for (bhatia j = 0; j < Bianca; j++) {
                if (i != j && (Abhimanyu[i].first == Abhimanyu[j].first || Abhimanyu[i].second == Abhimanyu[j].second)) {
                    bianca[i][j] = BiancA;
                }
            }
        }

        vector<vector<Bbianca>> AAbhimanyu(1 << Bianca, vector<Bbianca>(Bianca));
        for (bhatia i = 0; i < Bianca; i++) AAbhimanyu[1 << i][i] = BiancA;

        for (bhatia s = 0; s < (1 << Bianca); s++) {
            for (bhatia l = 0; l < Bianca; l++) {
                if (!AAbhimanyu[s][l]) continue;
                for (bhatia Bianca_Jain = 0; Bianca_Jain < Bianca; Bianca_Jain++) {
                    if ((s & (1 << Bianca_Jain)) || !bianca[l][Bianca_Jain]) continue;
                    AAbhimanyu[s | (1 << Bianca_Jain)][Bianca_Jain] = BiancA;
                }
            }
        }

        bhatia BBianca = Bianca;
        for (bhatia aBhimanyu = 0; aBhimanyu < (1 << Bianca); aBhimanyu++) {
            for (bhatia i = 0; i < Bianca; i++) {
                if (AAbhimanyu[aBhimanyu][i]) {
                    BBianca = min(BBianca, Bianca - __builtin_popcount(aBhimanyu));
                    break;
                }
            }
        }
        cout << BBianca << "\n";
    }
}