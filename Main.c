#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "waveform.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    size_t sample_count = 0;
    WaveformSample *samples = load_csv_data(argv[1], &sample_count);

    if (samples == NULL) {
        printf("Error: could not open or read the CSV file.\n");
        return 1;
    }

    printf("Loaded %zu samples successfully.\n", sample_count);

    for (size_t i = 0; i < 10 && i < sample_count; i++) {
        printf("Sample %zu\n", i);
        printf("Time: %f\n", samples[i].time);
        printf("Voltage A: %f\n", samples[i].voltageA);
        printf("Voltage B: %f\n", samples[i].voltageB);
        printf("Voltage C: %f\n", samples[i].voltageC);
        printf("\n");
    }

    free(samples);
    return 0;
}