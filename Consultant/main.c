#include <stdio.h>
#include <stdlib.h>
#include <hstring.h>

#include "../Utility/macrosDefinition.h"
#include "../Utility/utilityFunctions.h"
#include "../File Handling/fileHandlingFunctions.h"
#include "../Model/requestHandling.h"
#include "../Error Handling/errorHandling.h"

/**
 * The driving function of the program. Reads the information given by user
 * and executes data validation on it. In case the data given by user is
 * invalid, it prints respective message to the console and terminates.
 * Else, it invokes the appropriate functions, in order to handle the
 * user request.
 *
 * @return 0 if the data is valid and execution is completed successfully, else -1.
 * @author Vasileios Papastergios
 */
int main() {
    int numberOfRecordDates, numbers, metric;
    int **drawHistory = NULL;
    char *fileName = (char *) malloc(BUFFER_SIZE * sizeof(char));
    FILE *inputFilePointer = NULL;

    printf("Please give the multitude of numbers you want me to predict: ");
    scanf("%d", &numbers);

    printf("Please give the serial number of the metric you wish me to use: ");
    scanf("%d", &metric);

    printf("Please specify the file name that contains the data (e.g. data.txt): ");
    scanf("%s", fileName);
    fileName[strcspn(fileName, "\0")];

    if (!isInRange(numbers, LOWER_LIMIT_FOR_DRAWN_NUMBER, UPPER_LIMIT_FOR_DRAWN_NUMBER) ||
        !isInRange(metric, 0, NUMBER_OF_AVAILABLE_METRICS - 1)) {
        handleError(ERROR_INVALID_INPUT_NUMBERS);
    }

    inputFilePointer = fopen(fileName, "r");
    if (!inputFilePointer) handleError(ERROR_INVALID_DATA_FILE_NAME);
    drawHistory = readDataFromFile(inputFilePointer, &numberOfRecordDates);
    fclose(inputFilePointer);
    handleRequest(drawHistory, numberOfRecordDates, numbers, metric);

    free2DArray(drawHistory, numberOfRecordDates);
    free(fileName);
    return 0;
}
