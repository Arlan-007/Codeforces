#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int in[n];
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>in[i];
        arr[in[i]-1]=i+1;
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}