#include "Filter.h"
#include <stdlib.h>

void initMovingAverage(MovingAverageFilter *filter, int size) {
    filter->buffer = (double *)malloc(size * sizeof(double));
    filter->size = size;
    filter->index = 0;
    filter->sum = 0.0;

    // Buffer Initialization
    for (int i = 0; i < size; ++i) {
        filter->buffer[i] = 0.0;
    }
}

void updateMovingAverage(MovingAverageFilter *filter, double newValue) {

    filter->sum = filter->sum - filter->buffer[filter->index] + newValue;

    filter->buffer[filter->index] = newValue;
    filter->index = (filter->index + 1) % filter->size;
}

double getMovingAverage(const MovingAverageFilter *filter) {
    return filter->sum / filter->size;
}

void freeMovingAverage(MovingAverageFilter *filter) {
    free(filter->buffer);
    filter->buffer = NULL;
}
