#include <iostream>
using namespace std;

int main() {
    long long k,n;
    cin >> k >> n;
    long long odd = (k+1) / 2;
    if (n <= odd) cout << 2*n-1 << endl;
    else cout << 2*(n-odd) << endl;
    return 0;
}