#include <stdio.h>

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    printf("Enter size of Matrix A (rows cols): ");
    scanf("%d %d", &r1, &c1);
    printf("Enter size of Matrix B (rows cols): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Cannot multiply: incompatible sizes.\n");
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);
            
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("Result Matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
