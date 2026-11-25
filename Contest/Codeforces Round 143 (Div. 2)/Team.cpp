#include <iostream>
#include <vector>
using namespace std;

int main() {
    int ques_num;
    cin >> ques_num;
    vector <int> know;
    int temp;
    for (int i = 0; i < 3*ques_num; i++) {
        cin >> temp;
        know.push_back(temp);
    }
    int total = 0;
    for (int i = 0; i < 3*ques_num; i+=3) {
        if (know[i]+know[i+1]+know[i+2] >= 2) total++;
    }
    cout << total;
    return 0;
}