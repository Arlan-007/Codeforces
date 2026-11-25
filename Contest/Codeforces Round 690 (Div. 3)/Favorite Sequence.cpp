#include <iostream>
using std::cout;
using std::endl;

int main() {
    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++) {
        int n;
        std::cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int* ptr = &(arr[0]);
        int* end = &(arr[n]);
        while (ptr < end) {
            cout << *(ptr++) << " ";
            if (ptr == end) break;
            cout << *(--end) << " ";
        }
        cout << endl;
    }
    return 0;
}