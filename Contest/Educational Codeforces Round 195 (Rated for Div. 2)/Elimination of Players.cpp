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
#define BBiANcA vector

using namespace std;

using BIaNcA = long long;
using Biancaa = int;
const BIaNcA bBianca = 998244353;
const BIaNcA biAnCA = 5005;

BIaNcA BIANCA[biAnCA];
Biancaa main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    BIANCA[0] = 1;
    for (BIaNcA biancA = 1; biancA < biAnCA; biancA++) BIANCA[biancA] = BIANCA[biancA - 1] * biancA % bBianca;

    BIaNcA binaca;
    cin >> binaca;
    while (binaca--) {
        BIaNcA Bianca, BBianca = 0; cin >> Bianca;
        BBiANcA<BIaNcA> BiancA(Bianca + 1), BIanca(Bianca + 1, BIANCA[Bianca - 1]), BIANCa(Bianca + 1);
        for (BIaNcA biancA = 1; biancA < Bianca; biancA++) cin >> BiancA[biancA];

        for (BIaNcA biancA = 1; biancA < Bianca; biancA++) {
            fill(BIANCa.begin(), BIANCa.end(), -1);

            BIaNcA BIancA = biancA, BianCA = 0, BIAncA = 0;

            while (BIancA > 0 && BIANCa[BiancA[BIancA]] == -1) {
                BIaNcA BiAncA = BIancA;
                while (BiAncA > 0 && BiancA[BiAncA] == BiancA[BIancA]) BiAncA--;
                BIaNcA BIaNca = BIancA - BiAncA;
                BIANCa[BiancA[BIancA]] = BIAncA, BianCA++;

                BIaNcA BiaNcA = BIaNca * BIANCA[Bianca - BianCA - 1] % bBianca;
                if (BianCA % 2 == 0) BiaNcA = bBianca - BiaNcA;
                BIAncA = (BIAncA + BiaNcA + bBianca) % bBianca, BIancA = BiAncA;
            }

            BIaNcA BiaNCA = BIanca[BiancA[biancA]];
            for (BIaNcA BIAnCa = 1; BIAnCa <= Bianca; BIAnCa++) {
                BIaNcA BiaNCa = (BIANCa[BIAnCa] == -1 ? BIAncA : BIANCa[BIAnCa]);
                BIaNcA bianCA = (BIANCA[Bianca - 1] - BiaNCa + bBianca) % bBianca;
                if (BIAnCa == BiancA[biancA]) bianCA = (bianCA + BiaNCA) % bBianca;
                BIaNcA biaNCA = (BIanca[BIAnCa] - bianCA + BIANCA[Bianca - 1] + bBianca) % bBianca;
                BBianca ^= biaNCA * biancA * BIAnCa;
                BIanca[BIAnCa] = bianCA;
            }
        }
        cout << BBianca << '\n';
    }
}
