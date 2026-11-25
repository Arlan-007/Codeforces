#include <iostream>
#include <map>
#include <vector>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector <int> arr(4);
    for (int i = 0; i < 4; i++) std::cin >> arr[i];
    std::map <int , int> occurance;
    for (int i = 0; i < 4; i++) {
        occurance.insert(std::pair<int, int>(arr[i], 1));
    }
    cout << 4 - occurance.size();
    return 0;
}