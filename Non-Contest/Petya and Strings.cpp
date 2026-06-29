#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    char a[100],b[100];
    cin>>a>>b;
    for (int i = 0; a[i] != '\0'; i++) a[i] = tolower(a[i]);
    for (int i = 0; b[i] != '\0'; i++) b[i] = tolower(b[i]);
    int comp = strcmp(a, b);
    if (comp>0)cout<<1;
    else if (comp<0)cout<<-1;
    else cout<<0;
    return 0;
}