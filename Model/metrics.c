#include <stdlib.h>

#include "../Utility/macrosDefinition.h"
#include "metrics.h"
#include "../Error Handling/errorHandling.h"

/**
 * Constructs an array of integers that represents the frequency of appearance of
 * all the possibly drawn numbers.
 *
 * @param drawHistory a 2D array containing data from previous draws
 * @param numberOfRecordDates the number of rows the 2D array has (number of record dates)
 * @return an array that contains the number of appearances of all possibly drawn numbers
 */
int *constructFrequencyArray(int **drawHistory, int numberOfRecordDates) {
    int date, drawnNumber;
    int *appearanceFrequency = (int *) calloc(UPPER_LIMIT_FOR_DRAWN_NUMBER, sizeof(int));
    if (!appearanceFrequency) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

    for (date = 0; date < numberOfRecordDates; date++) {
        for (drawnNumber = 0; drawnNumber < NUMBERS_PER_DRAW; drawnNumber++) {
            appearanceFrequency[drawHistory[date][drawnNumber] - 1]++;
        }
    }

    return appearanceFrequency;
}

/**
 * Constructs an array of integers that represents the delay of appearance of
 * all the possibly drawn numbers. If the number does not exist in the records,
 * its delay is set equal to the number of recorder dates.
 *
 * @param drawHistory a 2D array containing data from previous draws
 * @param numberOfRecordDates the number of rows the 2D array has (number of record dates)
 * @return an array that contains the edlay of appearances of all possibly drawn numbers
 */
int *constructDelayArray(int **drawHistory, int numberOfRecordDates) {
    int date, drawnNumber, number;

    int *delay = (int *) malloc(UPPER_LIMIT_FOR_DRAWN_NUMBER * sizeof(int));
    if (!delay) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

    for (number = 0; number < UPPER_LIMIT_FOR_DRAWN_NUMBER; number++) {
        delay[number] = numberOfRecordDates;
    }

    for (date = 0; date < numberOfRecordDates; date++) {
        for (drawnNumber = 0; drawnNumber < NUMBERS_PER_DRAW; drawnNumber++) {
            if (delay[drawHistory[date][drawnNumber] - 1] > date) {
                delay[drawHistory[date][drawnNumber] - 1] = date;
            }
        }
    }

    return delay;
}

/**
 * Constructs an array of integers that represents the relative delay of appearance of
 * all the possibly drawn numbers.
 * relative_delay(n) = delay(n) - K / freq(n), where K is the number of record dates.
 * In case freq(n) = 0, then relative_delay(n) is set to 0.
 *
 * @param drawHistory a 2D array containing data from previous draws
 * @param numberOfRecordDates the number of rows the 2D array has (number of record dates)
 * @return an array that contains the edlay of appearances of all possibly drawn numbers
 */
float *constructRelativeDelayArray(int *appearanceFrequency, int *delay, int numberOfRecordDates) {
    int number;
    float *relativeDelay = (float *) calloc(UPPER_LIMIT_FOR_DRAWN_NUMBER, sizeof(float));
    if (!relativeDelay) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

    for (number = 0; number < UPPER_LIMIT_FOR_DRAWN_NUMBER; number++) {
        if (appearanceFrequency[number]) {
            relativeDelay[number] = delay[number] - ((float) numberOfRecordDates / appearanceFrequency[number]);
        }
    }

    return relativeDelay;
}