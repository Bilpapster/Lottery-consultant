#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macrosDefinition.h"
#include "utilityFunctions.h"

/**
 * Frees the memory allocated for a 2-dimensional array of integers.
 *
 * @param array2D the array pointer
 * @param numberOfRows the number of rows the 2-dimensional array has
 */
void free2DArray(int **array2D, int numberOfRows) {
    int row;
    for (row = 0; row < numberOfRows; row++) {
        free(array2D[row]);
    }
    free(array2D);
}

/**
 * Checks whether an 1-dimensional array contains the given number.
 *
 * @param array the array pointer
 * @param arrayLength the length of the array
 * @param numberToSearchFor the number to search for
 * @return 1 if the number is contained at least once, else 0
 */
char arrayContainsNumber(int *array, int arrayLength, int numberToSearchFor) {
    int index;

    for (index = 0; index < arrayLength; index++) {
        if (!(array[index] - numberToSearchFor)) {  // if (array[index] == numberToSearchFor)
            return 1;
        }
    }
    return 0;
}

/**
 * Simulates the operator A += B for two 1-dimensional arrays. The arrays must be of the same length.
 *
 * @param destinationArray the destination array pointer. Array A in the above example.
 * @param otherArray the right hand side array pointer. Array B in the above example.
 * @param arraysLength the length of the arrays.
 */
void addArrayToArray(int *destinationArray, int *otherArray, int arraysLength) {
    int index;
    for (index = 0; index < arraysLength; index++) {
        destinationArray[index] += otherArray[index];
    }
}

/**
 * Checks whether the given pointer is NULL or not. In case it is not NULL, it is freed.
 * Else, no operation is executed on it. Handles integer pointers.
 *
 * @param pointerToFree the pointer to check and free.
 */
void safeFreeInteger(int *pointerToFree) {
    if (pointerToFree) {
        free(pointerToFree);
    }
}

/**
 * Checks whether the given pointer is NULL or not. In case it is not NULL, it is freed.
 * Else, no operation is executed on it. Handles float pointers.
 *
 * @param pointerToFree the pointer to check and free.
 */
void safeFreeFloat(float *pointerToFree) {
    if (pointerToFree) {
        free(pointerToFree);
    }
}

/**
 * Swaps the value of two integers.
 * @param pointerA the first integer.
 * @param pointerB the second integer.
 */
void swapIntegers(int *pointerA, int *pointerB) {
    int temporary = *pointerA;
    *pointerA = *pointerB;
    *pointerB = temporary;
}

/**
 * Swaps the value of two float numbers.
 * @param pointerA the first float numbers.
 * @param pointerB the second float numbers.
 */
void swapFloat(float *pointerA, float *pointerB) {
    float temporary = *pointerA;
    *pointerA = *pointerB;
    *pointerB = temporary;
}

/**
 * Given an array of integers, constructs a parallel array with the respective indices.
 * Sorts the two parallel arrays in descending order, based on the given array values.
 * Returns the indices array.
 *
 * @param array the array to sort with indices
 * @param arrayLength the length of the array
 * @return the array if indices, sorted in parallel with the given array
 */
int *sortWithIndicesInteger(int *array, int arrayLength) {
    int i, j;
    int *indices = (int *) malloc(arrayLength * sizeof(int));

    for (i = 0; i < arrayLength; i++) {
        indices[i] = i;
    }

    for (i = 0; i < arrayLength - 1; i++) {
        for (j = 0; j < arrayLength - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                swapIntegers(&array[j], &array[j + 1]);
                swapIntegers(&indices[j], &indices[j + 1]);
            } else if ((array[j] == array[j + 1]) && (indices[j] > indices[j + 1])) {
                swapIntegers(&array[j], &array[j + 1]);
                swapIntegers(&indices[j], &indices[j + 1]);
            }
        }
    }

    return indices;
}

/**
 * Given an array of float numbers, constructs a parallel array with the respective indices.
 * Sorts the two parallel arrays in descending order, based on the given array values.
 * Returns the indices array.
 *
 * @param array the array to sort with indices
 * @param arrayLength the length of the array
 * @return the array if indices, sorted in parallel with the given array
 */
int *sortWithIndicesFloat(float *array, float arrayLength) {
    int i, j;
    int *indices = (int *) malloc(UPPER_LIMIT_FOR_DRAWN_NUMBER * sizeof(int));

    for (i = 0; i < arrayLength; i++) {
        indices[i] = i;
    }

    for (i = 0; i < arrayLength - 1; i++) {
        for (j = 0; j < arrayLength - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                swapFloat(&array[j], &array[j + 1]);
                swapIntegers(&indices[j], &indices[j + 1]);
            } else if ((array[j] == array[j + 1]) && (indices[j] > indices[j + 1])) {
                swapFloat(&array[j], &array[j + 1]);
                swapIntegers(&indices[j], &indices[j + 1]);
            }
        }
    }

    return indices;
}

/**
 * Prints to the console the first N elements of an array of integers. The integers are
 * printed on the same line, separated by one space each.
 *
 * @param array the array pointer
 * @param numberOfElements the multitude of numbers to print starting from the beginning of the array
 * @param offsetValue the offset value to add to each one of the printed integers
 */
void printFirstNElements(int *array, int numberOfElements, int offsetValue) {
    int index;
    for (index = 0; index < numberOfElements; index++) {
        printf("%d ", array[index] + offsetValue);
    }
}

/**
 * Checks whether an integer is within the closed range [lowerBound, upperBound].
 *
 * @param numberToCheck the number to check whether it belongs to the range or not
 * @param lowerBound the lower bound of the range (included)
 * @param upperBound the upper bound of the range (included)
 * @return true if the number belongs to the range, else false
 */
bool isInRange(int numberToCheck, int lowerBound, int upperBound) {
    return (!(numberToCheck < lowerBound || numberToCheck > upperBound));
}

