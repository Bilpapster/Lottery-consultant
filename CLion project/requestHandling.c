#include <stdio.h>
#include <stdlib.h>

#include "macrosDefinition.h"
#include "utilityFunctions.h"
#include "metrics.h"
#include "requestHandling.h"

/**
 * Handles a user request, defined by a multitude of asked numbers as well as a metric serial
 * number. Prints the asked data to the console.
 *
 * @param drawHistory the 2D table that contains the history data of the draws
 * @param numberOfRecordDates the number of draws contained in the table
 * @param numbers the multitude of numbers the user asks for
 * @param metric the serial number of the metric
 */
void handleRequest(int **drawHistory, int numberOfRecordDates, int numbers, int metric) {
    int *dataToAnalyze = NULL;
    int *appearanceFrequency = NULL;
    int *delay = NULL;
    float *relativeDelay = NULL;

    switch (metric) {
        case 0:
            dataToAnalyze = constructFrequencyArray(drawHistory, numberOfRecordDates);
            break;

        case 1:
            dataToAnalyze = constructDelayArray(drawHistory, numberOfRecordDates);
            break;

        case 2:
            dataToAnalyze = constructFrequencyArray(drawHistory, numberOfRecordDates);
            delay = constructDelayArray(drawHistory, numberOfRecordDates);
            addArrayToArray(dataToAnalyze, delay, UPPER_LIMIT_FOR_DRAWN_NUMBER);
            break;

        default:
            appearanceFrequency = constructFrequencyArray(drawHistory, numberOfRecordDates);
            delay = constructDelayArray(drawHistory, numberOfRecordDates);
            relativeDelay = constructRelativeDelayArray(appearanceFrequency, delay, numberOfRecordDates);
            free(appearanceFrequency);
            appearanceFrequency = sortWithIndicesFloat(relativeDelay, UPPER_LIMIT_FOR_DRAWN_NUMBER);
            printFirstNElements(appearanceFrequency, numbers, 1);

            free(delay);
            free(relativeDelay);
            return;
    }

    appearanceFrequency = sortWithIndicesInteger(dataToAnalyze, UPPER_LIMIT_FOR_DRAWN_NUMBER);
    printFirstNElements(appearanceFrequency, numbers, 1);

    safeFreeInteger(delay);
    safeFreeInteger(dataToAnalyze);
    safeFreeFloat(relativeDelay);
}


