# include <iostream>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    n--;
    cout << "I hate ";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << "that I love ";
        } else {
            cout << "that I hate ";
        }
    }
    cout << "it";
    return 0;
}