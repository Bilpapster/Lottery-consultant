#ifndef UTILITY_FUNCTIONS_H
#define UTILITY_FUNCTIONS_H

#include <stdbool.h>

char arrayContainsNumber(int *array, int arrayLength, int numberToSearchFor);

bool isInRange(int numberToCheck, int lowerBound, int upperBound);

void addArrayToArray(int *destinationArray, int *otherArray, int arraysLength);

void swapIntegers(int *pointerA, int *pointerB);

void swapFloat(float *pointerA, float *pointerB);

int *sortWithIndicesInteger(int *array, int arrayLength);

int *sortWithIndicesFloat(float *array, float arrayLength);

void printFirstNElements(int *array, int numberOfElements, int offsetValue);

void free2DArray(int **array2D, int numberOfRows);

void safeFreeInteger(int *pointerToFree);

void safeFreeFloat(float *pointerToFree);

#endif //UTILITY_FUNCTIONS_H
