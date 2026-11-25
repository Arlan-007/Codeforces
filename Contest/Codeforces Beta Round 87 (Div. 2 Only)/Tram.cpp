#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int passengers = 0;
    int in;
    int out;
    int max = 0;
    for (int i=0;i<n;i++) {
        cin>>out>>in;
        passengers -= out;
        passengers += in;
        if (passengers > max) {
            max = passengers;
        }
    }
    cout<<max<<endl;
    return 0;
}