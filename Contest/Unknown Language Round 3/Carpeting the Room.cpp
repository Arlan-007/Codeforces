# include <iostream>
using namespace std;

int main() {
    int n, k, n1;
    cin >> n >> k >> n1;
    int side = n/n1;
    if (n%n1 != 0) side++;
    int num = side*side;
    if (num > k) cout << "NO";
    else cout << "YES";
    return 0;
}