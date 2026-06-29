#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> score;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        score.push_back(x);
    }
    sort(score.rbegin(),score.rend());
    int least = score[k-1];
    int pass=0;
    for (int i = 0; i < n; i++) {
        if (score[i] >= least && score[i]>0) pass++;
    }
    cout << pass;
    return 0;
}