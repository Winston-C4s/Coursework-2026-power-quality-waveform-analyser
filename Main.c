#include <stdio.h>
#include <stdlib.h>
#include "io.h"         // include load_csv_data
#include "waveform.h"   // include WaveformSample 

// main function: get CSV file name, load data, and print a few samples
int main(int argc, char *argv[]) {
    
     // to check the user must provide the CSV file name
    if (argc != 2) {
        //  if the variable argc is not equal to 2, it means the user did not provide the correct number of arguments, so we print out a usage message to inform the user how to run the program correctly
        printf("Usage: %s <csv_file>\n", argv[0]);
        // return 1 to indicate that the program encountered an error due to incorrect usage and will exit without further execution
        return 1;
    }

    // store the number of samples loaded from the CSV file
    size_t sample_count = 0;
    
     // load the CSV data into memory
    WaveformSample *samples = load_csv_data(argv[1], &sample_count);

      // to stop the program if the file could not be opened or read
        if (samples == NULL) {
        printf("Error: could not open or read the CSV file.\n");
        // return 1 to indicate that the program encountered an error and will exit
        return 1;
    }

     // show how many samples were loaded
    printf("Loaded %zu samples successfully.\n", sample_count);
    // calculate RMS value using waveform samples and print it for the result
    double rmsA = calculate_rms_A(samples, sample_count);
    printf("RMS Voltage A: %.2f V\n", rmsA);

    //  to print out the first 10 samples (I set it 10 to prevent the output fill the screen)
    for (size_t i = 0; i < 10 && i < sample_count; i++) {
        // print the number of the sample being printed
        printf("Sample %zu\n", i);
        // print the sample's time value
        printf("Time: %f\n", samples[i].time);
        // print the sample's current A value
        printf("Voltage A: %f\n", samples[i].voltageA);
        // print the sample's current B value
        printf("Voltage B: %f\n", samples[i].voltageB);
        // print the sample's current C value
        printf("Voltage C: %f\n", samples[i].voltageC);
        // change the lines every time when the message being printed to make the output more clear
        printf("\n");
    }

    // release the memory 
    free(samples);
    
    // return 0 to indicate that the program executed successfully and will exit without errors
    return 0;
}
