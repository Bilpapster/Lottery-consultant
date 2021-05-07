#include <stdio.h>
#include <stdlib.h>

#include "../Utility/macrosDefinition.h"
#include "../Utility/utilityFunctions.h"
#include "fileHandlingFunctions.h"
#include "../Error Handling/errorHandling.h"

/**
 * Reads the data from the given text file. The data must have a specific
 * format: NUMBERS_PER_DRAW numbers per line, separated by one space.
 * Returns a 2D array that contains all the numbers of previous draws
 * contained in the text file.
 *
 * @param inputFilePointer the text file pointer that points to the
 * file to read data from.
 *
 * @param numberOfRecordDates the number of lines of the data file. The
 * value is returned to the caller function.
 *
 * @return a 2D int array with all the data contained in the file.
 *
 * @author Vasileios Papastergios
 */
int **readDataFromFile(FILE *inputFilePointer, int *numberOfRecordDates) {
    int **drawHistory = (int **) malloc(ALLOCATION_BLOCK_UNIT_SIZE * sizeof(int *));
    if (!drawHistory) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

    int drawnNumber;
    int **temp = NULL;
    int drawHistoryRows = ALLOCATION_BLOCK_UNIT_SIZE;
    char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if (!buffer) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

    int fileRow = -1;
    do {
        fileRow++;
        if (fileRow >= drawHistoryRows) {
            temp = (int **) realloc(drawHistory, (drawHistoryRows + ALLOCATION_BLOCK_UNIT_SIZE) * sizeof(int *));
            if (!temp) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

            drawHistoryRows += ALLOCATION_BLOCK_UNIT_SIZE;
            drawHistory = temp;
        }

        drawHistory[fileRow] = malloc(NUMBERS_PER_DRAW * sizeof(int));
        if (!drawHistory[fileRow]) handleError(ERROR_MEMORY_ALLOCATION_FAILURE);

        for (drawnNumber = 0; drawnNumber < NUMBERS_PER_DRAW; drawnNumber++) {
            fscanf(inputFilePointer, "%d", &drawHistory[fileRow][drawnNumber]);

            if (!isInRange(drawHistory[fileRow][drawnNumber], LOWER_LIMIT_FOR_DRAWN_NUMBER,
                           UPPER_LIMIT_FOR_DRAWN_NUMBER)) {
                fclose(inputFilePointer);
                handleError(ERROR_INVALID_DATA_INSIDE_DATA_FILE);
            }
        }

    } while (!feof(inputFilePointer));

    free(buffer);
    (*numberOfRecordDates) = ++fileRow;
    return (drawHistory);
}
