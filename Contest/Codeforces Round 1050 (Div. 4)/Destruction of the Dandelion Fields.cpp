#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    for (int j =0 ; j <t; j++) {
        long long cut = 0;
        cin>>n;
        long long arreven[n];
        long long arrodd[n];
        int odd = 0,even = 0;
        long long temp;
        for (int i=0;i<n;i++) {
            cin>>temp;
            if(temp%2==0) {
                arreven[even]=temp;
                even++;
            }
            else {
                arrodd[odd]=temp;
                odd++;
            }
        }
        for (int i=0;i< even; i++) {
            cut+=arreven[i];
        }
        sort(arrodd,arrodd+odd);
        int od;
        // if (odd%2!=0 && odd!=1) od = odd/2-1;
        od = odd/2;
        for (int i= od; i < odd; i++) {
            cut+=arrodd[i];
        }
        if (odd==0) cout<<0<<endl;
        else cout<<cut<<endl;
    }
    return 0;
}