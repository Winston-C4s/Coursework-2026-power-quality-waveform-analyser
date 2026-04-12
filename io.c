#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// ----------- Update-3: CSV File Loading
// This file reads waveform data from a CSV file
// and stores it into a WaveformSample array

WaveformSample *load_csv_data(const char *filename, size_t *count) {

    // -------- Update-3: Open the CSV file
    FILE *file = fopen(filename, "r");

    // stop if the file cannot be opened
    if (file == NULL) {
        return NULL;
    }

    // -------- Update-3: Create a buffer for one line of text
    char line[256];

    // -------- Update-3: Skip the header row
    // the first row contains column names, not waveform data
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return NULL;
    }

    // -------- Update-3: Set the maximum number of samples
    size_t max_samples = 1000;

    // -------- Update-3: Keep track of valid samples
    size_t i = 0;

    // -------- Update-2/3: Allocate memory for the sample array
    WaveformSample *samples = malloc(max_samples * sizeof(WaveformSample));

    // stop if memory allocation failed
    if (samples == NULL) {
        fclose(file);
        return NULL;
    }

    // -------- Update-3: Read the file line by line
    while (fgets(line, sizeof(line), file) != NULL) {

        // 8 values from one CSV row
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

        // only save the row if all 8 values were read correctly
        if (result == 8) {
            i++;
        }
    }

    // -------- Update-3: Close the file after reading
    fclose(file);

    // -------- Update-3: Return the number of valid samples
    *count = i;

    // return the pointer to the waveform sample array
    return samples;
}
