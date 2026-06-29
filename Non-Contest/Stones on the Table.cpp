# include <iostream>
using namespace std;

int main() {
    int num;
    cin>>num;
    string s;
    cin>>s;
    int count = 0;
    for (int i=0;i<num;i++) {
        if (s[i]==s[i+1]) count++;
    }
    cout<<count<<endl;
    return 0;
}