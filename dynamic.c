#include <stdio.h>
#include <stdlib.h>

int main() {
    int Rows = 3;
    int *Cols = (int *)malloc(Rows * sizeof(int));
    int **array = (int **)malloc(Rows * sizeof(int *));

    if (Cols == NULL || array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < Rows; i++) {
        Cols[i] = 3;
        array[i] = (int *)malloc(Cols[i] * sizeof(int));

        for (int j = 0; j < Cols[i]; j++) {
            array[i][j] = i * 20 + j + 1;
        }
    }

    printf("Original 2D array:\n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    int newRows = 4;
    array = (int **)realloc(array, newRows * sizeof(int *));
    if (array == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    
    for (int i = Rows; i < newRows; i++) {
        array[i] = NULL;
        Cols[i] = 0;
    }

    Rows = newRows;

    int rowIndex = 0;
    int newCols = 4;
    array[rowIndex] = (int *)realloc(array[rowIndex], newCols * sizeof(int));
    if (array[rowIndex] == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    for (int j = Cols[rowIndex]; j < newCols; j++) {
        array[rowIndex][j] = 0; 
    }

    Cols[rowIndex] = newCols;

    printf("2D array after increasing size:\n");
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols[i]; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < Rows; i++) {
        free(array[i]);
    }
    free(array);
    free(Cols);

    return 0;
}
