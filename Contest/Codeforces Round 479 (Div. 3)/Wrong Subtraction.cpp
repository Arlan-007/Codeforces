#include <iostream>
using namespace std;

int main() {
    int num,sub;
    cin>>num>>sub;
    while (sub>0) {
        if(num%10!=0) {
            num--;
        } else {
            num/=10;
        }
        sub--;
    }
    cout<<num;
    return 0;
}