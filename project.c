#include <stdio.h>
#include <stdlib.h>

int* resizeArray(int* array, int currentSize, int newSize) {
    int* newArray = (int*)realloc(array, newSize * sizeof(int));
    if (newArray == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize the new elements with zero if expanding the array
    if (newSize > currentSize) {
        for (int i = currentSize; i < newSize; ++i) {
            newArray[i] = 0;
        }
    }
    return newArray;
}

int main() {
    int currentSize, newSize;
    
    // Input the current size of the array
    printf("Enter the current size of the array: ");
    scanf("%d", &currentSize);
    
    // Dynamically allocate memory for the array
    int* array = (int*)malloc(currentSize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Input array elements
    printf("Enter %d elements for the array:\n", currentSize);
    for (int i = 0; i < currentSize; ++i) {
        scanf("%d", &array[i]);
    }
    
    // Input the new size of the array
    printf("Enter the new size of the array: ");
    scanf("%d", &newSize);
    
    // Resize the array
    array = resizeArray(array, currentSize, newSize);
    
    // Update the current size
    currentSize = newSize;
    
    // Output the resized array
    printf("Resized array:\n");
    for (int i = 0; i < currentSize; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free dynamically allocated memory
    free(array);
    
    return 0;
}


// 2 nd question
#include <stdio.h>
#include <stdlib.h>

int main() {
    int currentRows, currentCols, newRows, newCols;

    // Input the current number of rows and columns in the 2D array
    printf("Enter the current number of rows in the 2D array: ");
    scanf("%d", &currentRows);
    printf("Enter the current number of columns in the 2D array: ");
    scanf("%d", &currentCols);

    // Dynamically allocate memory for the initial 2D array and initialize its elements to zero
    int **array = (int **)malloc(currentRows * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < currentRows; ++i) {
        array[i] = (int *)malloc(currentCols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        // Initialize elements to zero
        for (int j = 0; j < currentCols; ++j) {
            array[i][j] = 0;
        }
    }

    // Input array elements
    printf("Enter elements for the 2D array:\n");
    for (int i = 0; i < currentRows; ++i) {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < currentCols; ++j) {
            scanf("%d", &array[i][j]);
        }
    }

    // Input the new number of rows and columns in the 2D array
    printf("Enter the new number of rows in the 2D array: ");
    scanf("%d", &newRows);
    printf("Enter the new number of columns in the 2D array: ");
    scanf("%d", &newCols);

    // Resize the 2D array
    array = (int **)realloc(array, newRows * sizeof(int *));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Adjust the number of rows
    if (newRows > currentRows) {
        for (int i = currentRows; i < newRows; ++i) {
            array[i] = (int *)malloc(newCols * sizeof(int));
            if (array[i] == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }
            // Initialize new row elements to zero
            for (int j = 0; j < newCols; ++j) {
                array[i][j] = 0;
            }
        }
    } else if (newRows < currentRows) {
        for (int i = newRows; i < currentRows; ++i) {
            free(array[i]);
        }
    }

    // Adjust the number of columns
    for (int i = 0; i < currentRows && i < newRows; ++i) {
        array[i] = (int *)realloc(array[i], newCols * sizeof(int));
        if (array[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        // Initialize new column elements to zero if expanding
        if (newCols > currentCols) {
            for (int j = currentCols; j < newCols; ++j) {
                array[i][j] = 0;
            }
        }
    }

    // Output the resized 2D array
    printf("Resized 2D array:\n");
    for (int i = 0; i < newRows; ++i) {
        printf("Row %d:\n", i + 1);
        for (int j = 0; j < newCols; ++j) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < newRows; ++i) {
        free(array[i]);
    }
    free(array);

    return 0;
}

// 3
#include <stdio.h>
#include <time.h>
int main(void)
{
struct tm* ptr;
time_t t;
t = time(NULL);
ptr = localtime(&t);
printf("%s", asctime(ptr));
return 0;
}

//4
#include <stdio.h>

// Macros
#define PI 3.14159
#define SQUARE(x) ((x) * (x))

// Conditional Compilation
#define DEBUG 1 // Change to 0 to disable debug messages

int main() {
    // Using Macros
    printf("Value of PI: %f\n", PI);
    printf("Square of 5: %d\n", SQUARE(5));

    // Using Conditional Compilation
    #if DEBUG
        printf("Debug Mode Enabled\n");
    #else
        printf("Debug Mode Disabled\n");
    #endif

    return 0;
}
