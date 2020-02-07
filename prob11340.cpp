#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    for (int j = 0; j < N; j++) {
        unordered_map<char, int> values;
        int K;
        scanf("%d", &K);
        char s[2]; int v;
        for (int i = 0; i < K; i++) {
            scanf("%s", &s);
            scanf("%d", &v);
            values[s[0]] = v;
        }

        int M;
        scanf("%d", &M);
        char line[10002];
        int cents = 0;
        for (int i = 0; i < M + 1; i++) {
            fgets(line, 10002, stdin);

            for (int k = 0; line[k] != '\0' || k < 10001; k++) {
                cents += values[line[k]];
            }
        }

        printf("%d.%d$\n", cents / 100, cents % 100);
    }

    return 0;
}