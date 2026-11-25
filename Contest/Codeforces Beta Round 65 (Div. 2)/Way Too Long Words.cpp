#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.length() > 10) {
            string temp = s.substr(0, 1);
            int a = s.length()-2;
            temp+=to_string(a);
            temp+=s[a+1];
            arr[i] = temp;
        } else {
            arr[i] = s;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i]<<endl;
    }
    return 0;
}