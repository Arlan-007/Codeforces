#include <iostream>
using namespace std;

int main() {
    int n,h;
    cin>>n>>h;
    int a[n];
    int width = 0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        width++;
        if (a[i]>h) {width++;}
    }
    cout<<width<<endl;
    return 0;
}