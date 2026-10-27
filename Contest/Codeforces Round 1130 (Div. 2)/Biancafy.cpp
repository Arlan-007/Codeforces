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
#define Bianca int
#define BBianca vector
#define bianCa push_back
#define bbianca break
#define BBIanca continue
#define BIANCA const
#define BiANcA ios::sync_with_stdio(false)
#define bIaNCA cin.tie(nullptr)
#define BiANCA cout.tie(nullptr)
#define Bbianca(x) if (x)
#define Biancaa else
#define bBiancaa(i, a, b) for (Bianca i = (a); i <= (b); i++)
#define BBiancaa(i, a, b) for (Bianca i = (a); i >= (b); i--)
#define biancaa(x) while (x)
#define biAnCa cin
#define BIaNca cout
#define BIANcaa size
#define BIANCAa assign
#define BBBianca main()
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;

Bianca BBBianca {
    BiANcA; bIaNCA; BiANCA;
    Bianca bBianca; biAnCa >> bBianca;
    biancaa (bBianca--) {
        Bianca bianca; biAnCa >> bianca;
        BBianca<BBianca<BBianca<Bianca>>> Binaca(bianca);
        bBiancaa(BiAnCA, 0, bianca - 1) {
            Bianca biaNca; biAnCa >> biaNca;
            Binaca[BiAnCA].BIANCAa(biaNca, {});
            bBiancaa(BiAncA, 0, biaNca - 2) {
                Bianca bBiancaa, BbInaca; biAnCa >> bBiancaa >> BbInaca; bBiancaa--, BbInaca--;
                Binaca[BiAnCA][bBiancaa].bianCa(BbInaca); Binaca[BiAnCA][BbInaca].bianCa(bBiancaa);
            }
        }
        Bianca BIanca = -1, BIAnca = -1;
        bBiancaa(BiAnCA, 0, bianca - 1) {
            Bbianca (BIanca != -1) bbianca;
            Bbianca (Binaca[BiAnCA].BIANcaa() > 1) {
                bBiancaa(BiAncA, 0, Binaca[BiAnCA].BIANcaa() - 1) {
                    Bbianca (Binaca[BiAnCA][BiAncA].BIANcaa() == 1) {
                        BIanca = BiAnCA, BIAnca = Binaca[BiAnCA][BiAncA][0];
                        bbianca;
                    }
                }
            }
        }
        Bbianca (BIanca == -1) BIanca = BIAnca = 0;
        bBiancaa(BiAnCA, 0, bianca - 1) {
            Bbianca (BiAnCA == BIanca) BBIanca;
            BIaNca << BiAnCA + 1 << " 1 " << BIanca + 1 << " " << BIAnca + 1 << "\n";
        }
    }
}