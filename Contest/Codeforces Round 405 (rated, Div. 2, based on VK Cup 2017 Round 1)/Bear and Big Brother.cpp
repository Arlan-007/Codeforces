#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    int count = 0;
    for (;;) {
        a*=3;
        b*=2;
        count++;
        if (a>b) {
            break;
        }
    }
    cout<<count;
    return 0;
}