#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// function to load waveform data from a CSV file
// returns a pointer to an array of WaveformSample
// and it writes the number of samples into *count
WaveformSample *load_csv_data(const char *filename, size_t *count) {

    // try to open the file in read mode
    FILE *file = fopen(filename, "r");

    // if the file cannot be opened, return NULL
    if (file == NULL) {
        return NULL;
    }

    // buffer to store each line from the file
    char line[256];

    // skip the first line because it is the header
    // most CSV files have column names in the first row
    // we do not want to parse that as data
    if (fgets(line, sizeof(line), file) == NULL) {
        // if we cannot even read the first line, something is wrong
        fclose(file);
        return NULL;
    }

    // set a maximum number of samples we expect
    size_t max_samples = 1000;

    // index to track how many valid samples we have read
    size_t i = 0;

    // allocate memory to store all samples
    WaveformSample *samples = malloc(max_samples * sizeof(WaveformSample));

    // check if memory allocation failed
    if (samples == NULL) {
        fclose(file);
        return NULL;
    }

    // read the file line by line until the end
    while (fgets(line, sizeof(line), file) != NULL) {

        // parse the line using sscanf
        // 8 values in each row
        int result = sscanf(
            line,
            "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
            &samples[i].time,
            &samples[i].voltageA,
            &samples[i].voltageB,
            &samples[i].voltageC,
            &samples[i].current,
            &samples[i].frequency,
            &samples[i].powerFactor,
            &samples[i].thd
        );

        // only store the data if all 8 values were read correctly
        // if result is not 8, the line is incomplete
        if (result == 8) {
            i++;
        }
    }

    // close the file after finishing reading
    fclose(file);

    // store the number of valid samples read
    *count = i;

    // return the pointer to the sample array
    return samples;
}