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
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        long long counter = 0;
        bool flag = false;
        for (;;) {
            bool changed = false;
            if (n == 1) {
                break;
            }
            for (int j = 0; j < n-1; j++) {
                while (arr[j] >= arr[j + 1]) {
                    if (arr[j] == 0) {
                        flag = true;
                        break;
                    }
                    counter++;
                    arr[j] = arr[j]/2;
                    changed = true;
                }
                if (flag) break;
            }
            if (!changed || flag) break;
        }
        cout << (flag ? -1 : counter) << '\n';
    }
    return 0;
}