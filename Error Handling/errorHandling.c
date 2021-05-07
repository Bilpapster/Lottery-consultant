#include <stdio.h>
#include <stdlib.h>

#include "../Utility/macrosDefinition.h"
#include "errorHandling.h"

/**
 * Handles the different error types that can occur during the execution of the program.
 * Prints appropriate error message and terminates the program with exit status -1.
 *
 * @param errorType the occurred error type to handle
 */
void handleError(int errorType) {
    switch (errorType) {
        case ERROR_INVALID_INPUT_NUMBERS:
            printf("Invalid input: Multitude of asked numbers or serial number of metric is out of bounds."
                   "Please make sure that the multitude of asked numbers is within the range[%d, %d], "
                   "and the serial number within the range [%d, %d].\n", LOWER_LIMIT_FOR_DRAWN_NUMBER,
                   UPPER_LIMIT_FOR_DRAWN_NUMBER, 0, NUMBER_OF_AVAILABLE_METRICS - 1);
            break;

        case ERROR_INVALID_DATA_FILE_NAME:
            printf("Invalid input: The data file indicated cannot be found. Please make sure you type the file"
                   "name correctly, including the file extension \'.txt\'. The file has to be located inside the "
                   "directory the executable file is located.\n");
            break;

        case ERROR_INVALID_DATA_INSIDE_DATA_FILE:
            printf("Invalid input: At least one number contained in the data file is out of the acceptable"
                   "bounds. Please make sure that all the numbers contained in the data file are in the range "
                   "[%d, %d].\n", LOWER_LIMIT_FOR_DRAWN_NUMBER, UPPER_LIMIT_FOR_DRAWN_NUMBER);
            break;

        case ERROR_MEMORY_ALLOCATION_FAILURE:
            printf("Memory allocation failure: A problem occurred during a try to allocate memory in order for"
                   "the program to execute properly. Memory allocation failure may be caused by vast amount of data."
                   " Please make sure there are no memory allocation limits imposed on the program and try again.\n");
            break;

        default:
            printf("Unknown error. The developer is to blame, please contact him.\n");
            // no default case for enhanced code readability
            // new error types, potentially added later on, must be handled here
            break;
    }
    exit(-1);
}
