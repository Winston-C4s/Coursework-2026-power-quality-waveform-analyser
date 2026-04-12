#include <math.h>
#include "waveform.h"

// ----------- Update-5: Phase A RMS Value Calculation

double calculate_rms_A(WaveformSample *samples, size_t count) {

    // -------- Update-5: Store the total of squared voltage values
    double sum_sq = 0.0;

    // -------- Update-5: Go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // square the phase A voltage and add it to the total
        sum_sq += samples[i].voltageA * samples[i].voltageA;
    }

    // -------- Update-5: Return the RMS value
    // divide by the number of samples, and then take the square root
    return sqrt(sum_sq / count);
}
