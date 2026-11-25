#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int total[n];
    int filled[n];
    int available = 0;
    for(int i=0;i<n;i++) {
        cin>>filled[i];
        cin>>total[i];
        if (total[i]-filled[i]>=2) available++;
    }
    cout<<available;
    return 0;
}