#include <iostream>
#include <vector>
#include <algorithm>
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
        std::vector<int> set(n, 1);
        long long counter = 0;
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::vector <int> shift = arr;
        while (arr != set) {
            std::rotate(shift.begin(), std::prev(shift.end()), shift.end());
            counter++;
            for (int j = n-1; j >= 0; j--) {
                if (shift[j] == 1) {
                    arr[j] = 1;

                }
            }
        }
        cout << counter << endl;
    }
}