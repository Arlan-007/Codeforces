#include <iostream>
using namespace std;

int main() {
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int cost,cost1,cost2;
    if (m*a >= b) {
        int sp_ticket = n/m;
        int norm_ticket = n%m;
        cost1 = sp_ticket*b + norm_ticket*a;
        cost2 = (sp_ticket+1)*b;
    } else {
        cost1 = n*a;
        cost2 = n*a;
    }
    // int cost_sp1,cost_sp2,cost_norm;
    // int sp_ticket = n/m;
    // int norm_ticket = n%m;
    // cost_sp1 = sp_ticket*b + norm_ticket*a;
    // cost_sp2 = (sp_ticket+1)*b;
    // cost_norm = n*a;
    // cost = min(cost_norm,min(cost_sp1,cost_sp2));
    cost = min(cost1,cost2);
    cout << cost;
    return 0;
}