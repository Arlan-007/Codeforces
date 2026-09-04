#include <stdio.h>

int main() {
    int n; scanf("%d", &n);
    int inter[200000][2];
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int l, r; scanf("%d %d", &l, &r);
        int merged_l = l, merged_r = r, new = 0;

        for (int j = 0; j < cnt; j++) {
            int a = inter[j][0];
            int b = inter[j][1];

            if ((merged_l <= b) && (a <= merged_r)) {
                if (a < merged_l) merged_l = a;
                if (b > merged_r) merged_r = b;
            } else {
                inter[new][0] = a;
                inter[new][1] = b;
                new++;
            }
        }

        inter[new][0] = merged_l;
        inter[new][1] = merged_r;
        cnt = new + 1;
        printf("%d\n", cnt);
    }
}
