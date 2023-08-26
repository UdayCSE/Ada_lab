#include <stdio.h>

#define MAX_ELEMENTS 10

int w[MAX_ELEMENTS], p[MAX_ELEMENTS], v[MAX_ELEMENTS][MAX_ELEMENTS], n, i, j, cap, x[MAX_ELEMENTS] = {0};

int max(int i, int j) {
    return ((i > j) ? i : j);
}

int knap(int i, int j) {
    int value;
    if (v[i][j] < 0) {
        if (j < w[i])
            value = knap(i - 1, j);
        else
            value = max(knap(i - 1, j), p[i] + knap(i - 1, j - w[i]));
        v[i][j] = value;
    }
    return v[i][j];
}

int main() {
    int profit, count = 0;

    printf("Enter the number of elements (max 10)\n");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_ELEMENTS) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter the profit and weights of the elements\n");
    for (i = 1; i <= n; i++) {
        printf("For item no %d\n", i);
        scanf("%d%d", &p[i], &w[i]);
    }

    printf("Enter the capacity \n");
    scanf("%d", &cap);
    if (cap <= 0) {
        printf("Invalid capacity.\n");
        return 1;
    }

    for (i = 0; i <= n; i++)
        for (j = 0; j <= cap; j++)
            if ((i == 0) || (j == 0))
                v[i][j] = 0;
            else
                v[i][j] = -1;

    profit = knap(n, cap);
    i = n;
    j = cap;

    while (j != 0 && i != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
            i--;
        } else
            i--;
    }

    printf("Items included are\n");
    printf("Sl.no\tweight\tprofit\n");
    for (i = 1; i <= n; i++)
        if (x[i])
            printf("%d\t%d\t%d\n", i, w[i], p[i]);


    printf("Total profit = %d\n", profit);

    return 0;
}