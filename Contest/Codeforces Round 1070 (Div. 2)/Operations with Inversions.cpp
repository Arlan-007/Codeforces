#include <iostream>
#include <vector>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        long long counter = 0;
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        for (int j = n-1; j >= 0; j--) {
            for (int k = j + 1; k < n; k++) {
                if (arr[k] < arr[j]) {
                    counter++;
                    arr[k] = 2147483647;
                }
            }
        }
        std::cout << counter << std::endl;
    }
    return 0;
}