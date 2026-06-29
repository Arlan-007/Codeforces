#include <iostream>
#include <vector>
using std::cout;
using std::endl;

bool game(std::vector <int> vec) {
    // if ( std::adjacent_find( vec.begin(), vec.end(), std::not_equal_to<>() ) == vec.end() ) {
    //     if ( vec[0] == 1 ) {
    //         return false;
    //     }
    //     if ( vec.size%2 == 0 ) {
    //         return true;
    //     }
    //     return false;
    // }
    if (vec.back() == 1 || vec[0] == 1) return false;
    return true;
}

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
        if (game(arr)) {
            cout << "BOB" << endl;
        } else {
            cout << "ALICE" << endl;
        }
    }
    return 0;
}