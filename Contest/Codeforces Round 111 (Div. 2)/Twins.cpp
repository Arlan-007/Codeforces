#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    sort(arr, arr + n, greater<int>());
    int mine = 0;
    for (int i = 1; i <= n; i++) {
        mine += arr[i-1];
        if (total/2 < mine) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}