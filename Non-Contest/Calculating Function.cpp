#include <iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    // int odd = n/2;
    // if (n%2!=0) odd++;
    // int even = n - odd;
    // double func = even*(even+1) - odd*(2+2*(odd-1))/2;
    long long func;
    if (n%2==0) {
        func=n/2;
    } else {
        func=-((n+1)/2);
    }
    cout<<func;
    return 0;
}