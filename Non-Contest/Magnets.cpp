#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1];
    a[0]=3;
    int count=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]!=a[i-1])count++;
    }
    cout<<count;
    return 0;
}