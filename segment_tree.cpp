#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;
int *t;

/*
    This tree is going to be built of the following logic
    Given n, the first index is the root index, the second and third are the first level,
    and so on. It gives the following structure for the tree, in terms of the index of the array
              1
        2          3
     4    5      6    7
    8 9 10 11 12 13 14 15
    So this tree can fit inside an array of at least 15. The following pattern can be established for 
    a parent and it's child. A parent with an index of n have children of (2n, 2n + 1).

    The array doesn't utilize the 0th index.
*/
void build_tree(int* a, int index_of_t, int tl, int tr) {
    if (tl == tr) {
        t[index_of_t] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build_tree(a, index_of_t * 2, tl, tm);
        build_tree(a, index_of_t * 2 + 1, tm + 1, tr);
        t[index_of_t] = t[2 * index_of_t] + t[2 * index_of_t + 1];
    }
}


/*
    To find the sum over a specific range, we first need to split the query who's range is l to r.
    In short, find a[l...r].

    There are three cases. If a[l...r] = a[tl...tr], then return the precomputed sum.
    
    The query could also fall completely onto one side. In that case, limit the ranges of the query
    
    Lastly, it could be split across the left subtree and the right subtree, which in that case,
    split the query across both subtree.
    a[l...tm] + a[tm...r]
*/
int rmq(int index_of_t, int l, int r, int tl, int tr) {
    if (l > r) {
        return 0;
    }

    if (l == tl && r == tr) {
        return t[index_of_t];
    }

    int tm = (tl + tr) / 2;
    return rmq(2 * index_of_t, tl, tm, l, min(r, tm)) 
           + rmq(2 * index_of_t + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int index_of_t, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[index_of_t] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2 * index_of_t, tl, tm, pos, new_val);
        } else {
            update(2 * index_of_t + 1, tm + 1, tr, pos, new_val);
        }
        t[index_of_t] = t[2 * index_of_t] + t[2 * index_of_t + 1];
    }
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *a = new int[n];
    t = new int[4 * n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Building array...\n");

    build_tree(a, 1, 0, n - 1);

    bool flag = false;
    char s[2];
    do {
        printf("What action do you want to take (S: sum, U: update, V: View, Q: quit)? ");
        scanf("%s", s);

        if (s[0] == 'S') {
            int l, r;
            printf("Enter the range of the query: ");
            scanf("%d", &l);
            scanf("%d", &r);
            int sum = rmq(1, 1, n, l, r);
            printf("Sum: %d\n", sum);
        } else if (s[0] == 'U') {
            int idx, new_val;
            printf("Enter the index: ");
            scanf("%d", &idx);
            printf("Enter the new value: ");
            scanf("%d", &new_val);
            update(1, 1, n, idx, new_val);
        } else if (s[0] == 'V') {
            int size = (int)pow(2, floor(log2(n)) - 1);
            printf("%d %d\n", size, n);
            for (int i = 1; i <= size + n; i++) {
                printf("%d ", t[i]);
                if (!((i + 1) & i)) {
                    printf("\n");
                }
            }
            printf("\n");
        } else {
            flag = true;
        }
        
    } while (!flag);

    delete[] a;
    delete[] t;

    return 0;
}
