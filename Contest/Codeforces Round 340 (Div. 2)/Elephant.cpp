#include <iostream>
using namespace std;

int main() {
    int coords;
    cin>>coords;
    int moves = coords/5;
    if (coords%5 != 0) moves++;
    cout<<moves;
    return 0;
}