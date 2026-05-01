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

    // -------- Update-13: Calculate RMS for phases A, B, and C
    double rmsA = rms(samples, sample_count, 'A');
    double rmsB = rms(samples, sample_count, 'B');
    double rmsC = rms(samples, sample_count, 'C');
    //--------Update-5: Calculate RMS, this is the first analysis result added to the program
    printf("Analysis Results:\n");
    printf("RMS Voltage A: %.2f V\n", rmsA);
    printf("RMS Voltage B: %.2f V\n", rmsB);
    printf("RMS Voltage C: %.2f V\n", rmsC);
    printf("----------------------------------------------\n");
    //--------Update-6: Calculate Peak-to-Peak, this is the second analysis result added to the program
    double ptpA = peak_to_peak(samples, sample_count, 'A');
    double ptpB = peak_to_peak(samples, sample_count, 'B');
    double ptpC = peak_to_peak(samples, sample_count, 'C');
    printf("Peak-to-Peak Voltage Analysis:\n");
    printf("Peak-to-Peak Voltage A: %.2f V\n", ptpA);
    printf("Peak-to-Peak Voltage B: %.2f V\n", ptpB);
    printf("Peak-to-Peak Voltage C: %.2f V\n", ptpC);
    printf("----------------------------------------------\n");
    //--------Update-7: Calculate DC Offset, this is the third analysis result added to the program
    double dcA = DC_offset(samples, sample_count, 'A');
    double dcB = DC_offset(samples, sample_count, 'B');
    double dcC = DC_offset(samples, sample_count, 'C');
    printf("DC Offset Voltage Analysis:\n");
    printf("DC Offset Voltage A: %.2f V\n", dcA);
    printf("DC Offset Voltage B: %.2f V\n", dcB);
    printf("DC Offset Voltage C: %.2f V\n", dcC);
    printf("----------------------------------------------\n");
    //--------Update-8: Clipp ing detection, this is the fourth analysis result added to the program
    int clipping = clipping_detection(samples, sample_count, 'A');
    int clippingB = clipping_detection(samples, sample_count, 'B');
    int clippingC = clipping_detection(samples, sample_count, 'C');
    printf("Clipping Detection Analysis:\n");
    if (clipping > 0) {
        printf("Clipping count A: %d\n", clipping);
    } else {
        printf("No clipping detected in Voltage A.\n");
    }
    if (clippingB > 0) {
        printf("Clipping count B: %d\n", clippingB);
    } else {
        printf("No clipping detected in Voltage B.\n");
    }
    if (clippingC > 0) {
        printf("Clipping count C: %d\n", clippingC);
    } else {
        printf("No clipping detected in Voltage C.\n");
    }
    printf("----------------------------------------------\n");
    //--------Update-9: Compliance check, this is the fifth analysis result added to the program
    int compliance = compliance_check(samples, sample_count, 'A');
    int complianceB = compliance_check(samples, sample_count, 'B');
    int complianceC = compliance_check(samples, sample_count, 'C');
    printf("Compliance Check Analysis:\n");
    if (compliance == 1) {
        printf("Voltage A is compliant\n");
    } else {
        printf("Voltage A is not compliant\n");
    }
    if (complianceB == 1) {
        printf("Voltage B is compliant\n");
    } else {
        printf("Voltage B is not compliant\n");
    }
    if (complianceC == 1) {
        printf("Voltage C is compliant\n");
    } else {
        printf("Voltage C is not compliant\n");
    }
    printf("----------------------------------------------\n");
        //--------Update-10: Mean frequency analysis, this is the sixth analysis result added to the program
    double meanFreq = mean_frequency(samples, sample_count);
    printf("Mean Frequency: %.2f Hz\n", meanFreq);
    //--------Update-11: Mean power factor analysis, this is the seventh analysis result added to the program
    double meanPF = mean_power_factor(samples, sample_count);
    printf("----------------------------------------------\n");
    printf("Mean Power Factor: %.2f\n", meanPF);
    //--------Update-12: Mean THD analysis, this is the eighth analysis result added to the program
    double meanTHD = mean_THD(samples, sample_count);
    printf("----------------------------------------------\n");
    printf("Mean THD: %.2f %%\n", meanTHD);

    // Update-4: Print the first 10 samples (only for checking the loaded waveform data)
        printf("----------------------------------------------\n");
        printf("First 10 Samples:\n");
    for (size_t i = 0; i < 10 && i < sample_count; i++) {
                printf("----------------------------------------------\n");
                printf("Sample %zu\n", i);
                printf("Time: %f\n", samples[i].time);
                printf("Voltage A: %f\n", samples[i].voltageA);
                printf("Voltage B: %f\n", samples[i].voltageB);
                printf("Voltage C: %f\n", samples[i].voltageC);
                printf("\n");
    }
    printf("----------------------------------------------\n");
//--------Update-15: Write results to a text file, this is the final step of the program to save the analysis results for later review
FILE *output = fopen("results.txt", "w");
if (output == NULL) {
    //--if the file cannot be created, print an error message and exit
    printf("Error: could not create the output file.\n");
    return 1;
}
//--Write the analysis results to the file, this includes all the results calculated in the previous steps
fprintf(output, "Power Quality Analysis Results\n");
fprintf(output, "Input file: power_quality_log.csv\n");
fprintf(output, "Samples loaded: 1000\n");
fprintf(output, "Analysis Results:\n");
fprintf(output, "RMS Voltage A: %.2f V\n", rmsA);
fprintf(output, "RMS Voltage B: %.2f V\n", rmsB);
fprintf(output, "RMS Voltage C: %.2f V\n", rmsC);
fprintf(output, "Peak-to-Peak Voltage A: %.2f V\n", ptpA);
fprintf(output, "Peak-to-Peak Voltage B: %.2f V\n", ptpB);
fprintf(output, "Peak-to-Peak Voltage C: %.2f V\n", ptpC);
fprintf(output, "DC Offset Voltage A: %.2f V\n", dcA);
fprintf(output, "DC Offset Voltage B: %.2f V\n", dcB);
fprintf(output, "DC Offset Voltage C: %.2f V\n", dcC);
// Clipping results
if (clipping > 0) {
    fprintf(output, "Clipping count A: %d\n", clipping);
} else {
    fprintf(output, "No clipping detected in Voltage A.\n");
}

if (clippingB > 0) {
    fprintf(output, "Clipping count B: %d\n", clippingB);
} else {
    fprintf(output, "No clipping detected in Voltage B.\n");
}

if (clippingC > 0) {
    fprintf(output, "Clipping count C: %d\n", clippingC);
} else {
    fprintf(output, "No clipping detected in Voltage C.\n");
}
// Compliance results
if (compliance == 1) {
    fprintf(output, "Voltage A is compliant\n");
} else {
    fprintf(output, "Voltage A is not compliant\n");
}

if (complianceB == 1) {
    fprintf(output, "Voltage B is compliant\n");
} else {
    fprintf(output, "Voltage B is not compliant\n");
}

if (complianceC == 1) {
    fprintf(output, "Voltage C is compliant\n");
} else {
    fprintf(output, "Voltage C is not compliant\n");
}
// Mean frequency, power factor, and THD results
fprintf(output, "Mean Frequency: %.2f Hz\n", meanFreq);
fprintf(output, "Mean Power Factor: %.2f\n", meanPF);
fprintf(output, "Mean THD: %.2f %%\n", meanTHD);
// Close the file after writing, this is important to ensure that all data is saved properly
fclose(output);
printf("Results have been written to results.txt\n");
    //----Update-4: Free allocated memory, always free memory after finishing the function
free(samples);
samples = NULL;
    return 0;
}
