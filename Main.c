#include <stdio.h>
#include <stdlib.h>
#include "io.h"         //-load_csv_data is used here
#include "waveform.h"   //-WaveformSample and RMS function are used here

// -----------Update-4-Display Loaded Data
// -----------Update-5-Phase A RMS Value Calculation

int main(int argc, char *argv[]) {

    //--------Update-4: Check command-line input
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }
    //--------Update-4: Prepare a variable to store sample count, this will store how many rows were loaded from the CSV
    size_t sample_count = 0;

    //---------Update-3/4: Load CSV data into memory
    WaveformSample *samples = load_csv_data(argv[1], &sample_count);

    //--------stop the program if loading failed
    if (samples == NULL) {
        printf("Error: could not open or read the CSV file.\n");
        return 1;
    }

    //--------Update-4: Show loading result, this helps confirm that the CSV file was read correctly
    printf("Loaded %zu samples successfully.\n", sample_count);

    //--------Update-5: Calculate RMS for phase A, this is the first analysis result added to the program
    double rmsA = rms_A(samples, sample_count);
    printf("RMS Voltage A: %.2f V\n", rmsA);
    //--------Update-6: Calculate Peak-to-Peak for phase A, this is the second analysis result added to the program
    double ptpA = peak_to_peak_A(samples, sample_count);
    printf("Peak-to-Peak Voltage A: %.2f V\n", ptpA);
    //--------Update-7: Calculate DC Offset for phase A, this is the third analysis result added to the program
    double dcA = DC_offset_A(samples, sample_count);
    printf("DC Offset Voltage A: %.2f V\n", dcA);
    //--------Update-8: Clipping detection for phase A, this is the fourth analysis result added to the program
    int clippingA = clipping_detection_A(samples, sample_count);
    if (clippingA > 0) {
        printf("Clipping count A: %d\n", clippingA);
    } else {
        printf("No clipping detected in Voltage A.\n");
    }
    //--------Update-9: Compliance check for phase A, this is the fifth analysis result added to the program
    int complianceA = compliance_check_A(samples, sample_count);
    if (complianceA == 1) {
        printf("Voltage A is compliant\n");
    } else {
        printf("Voltage A is not compliant\n");
    }
        //--------Update-10: Mean frequency analysis for phase A, this is the sixth analysis result added to the program
    double meanFreqA = mean_frequency_A(samples, sample_count);
    printf("Mean Frequency A: %.2f Hz\n", meanFreqA);
    //--------Update-11: Mean power factor analysis for phase A, this is the seventh analysis result added to the program
    double meanPFA = mean_power_factor_A(samples, sample_count);
    printf("Mean Power Factor A: %.2f\n", meanPFA);
    //--------Update-12: Mean THD analysis for phase A, this is the eighth analysis result added to the program
    double meanTHDA = mean_THD_A(samples, sample_count);
    printf("Mean THD A: %.2f %%\n", meanTHDA);

    // Update-4: Print the first 10 samples (only for checking the loaded waveform data)
    for (size_t i = 0; i < 10 && i < sample_count; i++) {
        printf("Sample %zu\n", i);
        printf("Time: %f\n", samples[i].time);
        printf("Voltage A: %f\n", samples[i].voltageA);
        printf("Voltage B: %f\n", samples[i].voltageB);
        printf("Voltage C: %f\n", samples[i].voltageC);
        printf("\n");
    }
    //----Update-4: Free allocated memory, always free memory after finishing the function
    free(samples);

    return 0;
}
