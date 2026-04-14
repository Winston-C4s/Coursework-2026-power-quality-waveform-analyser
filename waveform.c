#include <math.h>
#include "waveform.h"

// ----------- Update-5: Phase A RMS Value Calculation

double rms_A(WaveformSample *samples, size_t count) {

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
double peak_to_peak_A(WaveformSample *samples, size_t count) {
    if (count == 0) {
    return 0.0;
}
    // -------- Update-6: Store the total of max and min voltage values
    double max_volt = samples[0].voltageA;
    double min_volt = samples[0].voltageA;

    // -------- Update-6: Go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // update max and min voltage values
        if (samples[i].voltageA > max_volt) {
            max_volt = samples[i].voltageA;
        }
        if (samples[i].voltageA < min_volt) {
            min_volt = samples[i].voltageA;
        }
    }

    // -------- Update-6: Return the peak-to-peak value
    return max_volt - min_volt;
}
double DC_offset_A(WaveformSample *samples, size_t count) {

    // -------- Update-7: dc offset is the average voltage value, so we need to store the total of voltage values
    double sum = 0.0;

    // -------- Update-7: Go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // add the phase A voltage to the total
        sum += samples[i].voltageA;
    }

    // -------- Update-7: Return the DC offset value
    // divide by the number of samples
    return sum / count;
}
int clipping_detection_A(WaveformSample *samples, size_t count) {

    // -------- Update-8: store how many clipped samples are found
    int clip_count = 0;

    // -------- Update-8: go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // if phase A voltage reaches the clipping threshold, count it
        if (samples[i].voltageA >= 324.9 || samples[i].voltageA <= -324.9) {
            clip_count++;
        }
    }

    // -------- Update-8: return the number of clipped samples
    return clip_count;
}
    int compliance_check_A(WaveformSample *samples, size_t count) {
        // -------- Update-9: calculate the RMS value for phase A
        double rms_value = rms_A(samples, count);

        // -------- Update-9: if phase A voltage exceeds the compliance limit, count it
        if (rms_value >= 207.0 && rms_value <= 253.0) {
            return 1; // if is compliant
        } else {
            return 0; // if is non-compliant
        }
    }
