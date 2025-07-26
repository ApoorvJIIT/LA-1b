#include <stdio.h>

void transpose(int mat[100][100], int n) {
    for (int r = 0; r < n; r++) {
        for (int c = r + 1; c < n; c++) {
            int temp = mat[r][c];
            mat[r][c] = mat[c][r];
            mat[c][r] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int mat[100][100];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    transpose(mat, n);

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}