# include <iostream>
using std::cout;
using std::endl;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1,s2; std::cin >> s1 >> s2;
    std::string s = "";
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) s += "0";
        else s += "1";
    }
    cout << s;

    return 0;
}