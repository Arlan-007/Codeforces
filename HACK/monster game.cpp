#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <limits>
using namespace std;
#define int long long
const int mxn=2e5+5;
int n,a[mxn],b[mxn];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+n+1);reverse(a+1,a+n+1);
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        sum+=b[i];
        if(sum>n)break;
        int t=a[sum];
        ans=max(ans,t*i);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    cin>>T;
    for(;T--;)solve();
    return 0;
}

