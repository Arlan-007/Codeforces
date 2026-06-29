#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    double sum=0;
    double temp;
    for(int i=0;i<n;i++) {
        cin>>temp;
        sum+=temp;
    }
    double average=(sum/n);
    cout<<average;
    return 0;
}