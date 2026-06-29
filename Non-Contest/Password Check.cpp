#include <iostream>
#include <cctype>
#include <iomanip>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    bool length = (int)s.size() >= 5;
    bool upper = false, lower = false, digit = false;
    for (int i=0; i < s.size(); i++) {
        if (isupper(s[i])) upper = true;
        if (islower(s[i])) lower = true;
        if (isdigit(s[i])) digit = true;
    }
    if (length && upper && lower && digit) cout << "Correct" << endl;
    else cout << "Too weak" << endl;
    return 0;
}