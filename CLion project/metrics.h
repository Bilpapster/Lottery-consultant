#ifndef UNTITLED_METRICS_H
#define UNTITLED_METRICS_H

int *constructFrequencyArray(int **drawHistory, int numberOfRecordDates);

int *constructDelayArray(int **drawHistory, int numberOfRecordDates);

float *constructRelativeDelayArray(int *appearanceFrequency, int *delay, int numberOfRecordDates);

#endif //UNTITLED_METRICS_H
