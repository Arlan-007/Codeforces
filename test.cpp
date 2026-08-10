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

typedef long long ll;
typedef pair<int,int>  pii;
typedef pair<ll,ll>    pll;
typedef vector<int>    vi;
typedef vector<ll>     vll;
typedef vector<pii>    vpii;
typedef vector<pll>    vpll;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;

#define loop(i,n)      for(int i=0;i<(n);i++)
#define loop1(i,n)     for(int i=1;i<=(n);i++)
#define loopd(i,a,b)   for(int i=(a);i<=(b);i++)
#define rloop(i,n)     for(int i=(n)-1;i>=0;i--)

#define all(x)    (x).begin(),(x).end()
#define rall(x)   (x).rbegin(),(x).rend()
#define pb        push_back

int digit_sum (string s) {
    int sum = 0;
    for (auto c : s) {
        sum += c - '0';
    }
    return sum;
}

string build (int num) {
    string s = to_string(num);
    while (num>=10) {
        num = digit_sum(to_string(num));
        s += to_string(num);
    }
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int num=digit_sum(s);

        // added special for single digit cause this was casue problem for me
        int n = s.size();
        if(n == 1){
            cout << s << "\n";
            continue;
        }

        vi freq(10,0);
        string ans;
        for (auto &c : s) freq[c-'0']++;
        for (int i=1;i<=num;i++) {
            bool flag=true;
            string s1=build(i);

            // check this before doing following operation this cuts most of the checks
            // so doing it before saves a lot of time.
            int s1_sum = 0;
            for (char c : s1) s1_sum += c - '0';
            if (num - s1_sum != i) continue;


            for (auto &it:s1) {
                freq[it-'0']--;
                if (freq[it-'0']<0) flag=false;
            }
            if (flag) {
                string ans1;
                int k=0;
                for (int j=9;j>=0;j--) {
                    for (int z=0;z<freq[j];z++) {
                        ans1.pb(j+'0');
                    }
                    k+=freq[j]*(j);
                }
                if (k==i || ans1.empty()) {
                    ans1+=s1;
                    ans=ans1;
                    break;
                }
            }
            for (auto &it:s1) {
                freq[it-'0']++;
            }
        }
        cout<<ans<<'\n';
    }
}