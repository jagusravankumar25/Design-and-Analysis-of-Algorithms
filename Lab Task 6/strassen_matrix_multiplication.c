#include <stdio.h>
#include <stdlib.h>

void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int (*A11)[k] = malloc(sizeof(int[k][k]));
    int (*A12)[k] = malloc(sizeof(int[k][k]));
    int (*A21)[k] = malloc(sizeof(int[k][k]));
    int (*A22)[k] = malloc(sizeof(int[k][k]));
    int (*B11)[k] = malloc(sizeof(int[k][k]));
    int (*B12)[k] = malloc(sizeof(int[k][k]));
    int (*B21)[k] = malloc(sizeof(int[k][k]));
    int (*B22)[k] = malloc(sizeof(int[k][k]));

    int (*M1)[k] = malloc(sizeof(int[k][k]));
    int (*M2)[k] = malloc(sizeof(int[k][k]));
    int (*M3)[k] = malloc(sizeof(int[k][k]));
    int (*M4)[k] = malloc(sizeof(int[k][k]));
    int (*M5)[k] = malloc(sizeof(int[k][k]));
    int (*M6)[k] = malloc(sizeof(int[k][k]));
    int (*M7)[k] = malloc(sizeof(int[k][k]));
    int (*T1)[k] = malloc(sizeof(int[k][k]));
    int (*T2)[k] = malloc(sizeof(int[k][k]));

    if (!A11 || !A12 || !A21 || !A22 ||
        !B11 || !B12 || !B21 || !B22 ||
        !M1 || !M2 || !M3 || !M4 || !M5 || !M6 || !M7 ||
        !T1 || !T2) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(k, A11, A22, T1);
    addMatrix(k, B11, B22, T2);
    strassen(k, T1, T2, M1);

    // M2 = (A21 + A22) * B11
    addMatrix(k, A21, A22, T1);
    strassen(k, T1, B11, M2);

    // M3 = A11 * (B12 - B22)
    subMatrix(k, B12, B22, T2);
    strassen(k, A11, T2, M3);

    // M4 = A22 * (B21 - B11)
    subMatrix(k, B21, B11, T2);
    strassen(k, A22, T2, M4);

    // M5 = (A11 + A12) * B22
    addMatrix(k, A11, A12, T1);
    strassen(k, T1, B22, M5);

    // M6 = (A21 - A11) * (B11 + B12)
    subMatrix(k, A21, A11, T1);
    addMatrix(k, B11, B12, T2);
    strassen(k, T1, T2, M6);

    // M7 = (A12 - A22) * (B21 + B22)
    subMatrix(k, A12, A22, T1);
    addMatrix(k, B21, B22, T2);
    strassen(k, T1, T2, M7);

    // C11 = M1 + M4 - M5 + M7
    // C12 = M3 + M5
    // C21 = M2 + M4
    // C22 = M1 - M2 + M3 + M6
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k] = M3[i][j] + M5[i][j];
            C[i + k][j] = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }

    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(M1); free(M2); free(M3); free(M4);
    free(M5); free(M6); free(M7);
    free(T1); free(T2);
}

int nextPowerOfTwo(int n) {
    int p = 1;
    while (p < n) {
        p *= 2;
    }
    return p;
}

int main(void) {
    int n;

    printf("Enter matrix size n for n x n matrices: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Matrix size must be positive.\n");
        return 1;
    }

    // Strassen works naturally with powers of two.
    // Smaller matrices are padded with zeros.
    int s = nextPowerOfTwo(n);

    int (*A)[s] = calloc((size_t)s, sizeof(*A));
    int (*B)[s] = calloc((size_t)s, sizeof(*B));
    int (*C)[s] = calloc((size_t)s, sizeof(*C));

    if (!A || !B || !C) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(A);
        free(B);
        free(C);
        return 1;
    }

    printf("Enter matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter matrix B (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(s, A, B, C);

    printf("Product matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}
