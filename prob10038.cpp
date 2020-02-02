#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        vector<int> ray(n);
        vector<int> diff(n - 1);
        for (int i = 0; i < n; i++) {
            scanf("%d", &ray[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            diff[i] = abs(ray[i + 1] - ray[i]);
        }
        sort(diff.begin(), diff.end());
        bool flag = true;
        for (int i = 0; i < n - 1 && flag; i++) {
            if (diff[i] != i + 1) {
                flag = false;
            }
        }
        if (flag) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
}
