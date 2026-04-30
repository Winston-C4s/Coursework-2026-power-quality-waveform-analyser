#include <math.h>
#include "waveform.h"
//-----------Update-13: Phase B and C analysis functions
double get_phase_voltage(WaveformSample sample, char phase) {
    switch (phase) {
        case 'A':
            return sample.voltageA;
        case 'B':
            return sample.voltageB;
        case 'C':
            return sample.voltageC;
        default:
            return 0.0; // Return 0 for invalid phase input
    }
}
// ----------- Update-5: Phase A RMS Value Calculation

double rms(WaveformSample *samples, size_t count, char phase) {
    if (count == 0) {
        return 0.0;
    }
    
    double sum_sq = 0.0;
    
    //--------Update-16 change the loop to pointer arithmetic for better performance
    WaveformSample *ptr = samples;
    WaveformSample *end = samples + count;
    
    while (ptr < end) {
        double v = get_phase_voltage(*ptr, phase);
        sum_sq += v * v;
        ptr++;
    }
    
    return sqrt(sum_sq / count);
}
double peak_to_peak(WaveformSample *samples, size_t count, char phase) {
    if (count == 0) {
    return 0.0;
}
    // -------- Update-6: Store the total of max and min voltage values
    double max_volt = get_phase_voltage(samples[0], phase);
    double min_volt = get_phase_voltage(samples[0], phase);

    // -------- Update-6: Go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // update max and min voltage values
        if (get_phase_voltage(samples[i], phase) > max_volt) {
            max_volt = get_phase_voltage(samples[i], phase);
        }
        if (get_phase_voltage(samples[i], phase) < min_volt) {
            min_volt = get_phase_voltage(samples[i], phase);
        }
    }

    // -------- Update-6: Return the peak-to-peak value
    return max_volt - min_volt;
}
double DC_offset(WaveformSample *samples, size_t count, char phase) {
        if (count == 0) {
    return 0.0;
    }
    // -------- Update-7: dc offset is the average voltage value, so we need to store the total of voltage values
    double sum = 0.0;

    // -------- Update-7: Go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // add the phase A voltage to the total
        sum += get_phase_voltage(samples[i], phase);
    }

    // -------- Update-7: Return the DC offset value
    // divide by the number of samples
    return sum / count;
}
int clipping_detection(WaveformSample *samples, size_t count, char phase) {

    // -------- Update-8: store how many clipped samples are found
    int clip_count = 0;

    // -------- Update-8: go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // if phase A voltage reaches the clipping threshold, count it
        if (get_phase_voltage(samples[i], phase) >= 324.9 || get_phase_voltage(samples[i], phase) <= -324.9) {
            clip_count++;
        }
    }

    // -------- Update-8: return the number of clipped samples
    return clip_count;
}
    int compliance_check(WaveformSample *samples, size_t count, char phase) {
        // -------- Update-9: calculate the RMS value for the specified phase
        double rms_value = rms(samples, count, phase);

        // -------- Update-9: if phase A voltage exceeds the compliance limit, count it
        if (rms_value >= 207.0 && rms_value <= 253.0) {
            return 1; // if is compliant
        } else {
            return 0; // if is non-compliant
        }
    }
double mean_frequency(WaveformSample *samples, size_t count) {
    // -------- Update-10: store the total of frequency values
    double sum_freq = 0.0;

    // -------- Update-10: go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // add the frequency value to the total
        sum_freq += samples[i].frequency;
    }

    // -------- Update-10: return the mean frequency value
    // divide by the number of samples
    return sum_freq / count;
}
double mean_power_factor(WaveformSample *samples, size_t count) {
    // -------- Update-11: store the total of power factor values
    double sum_pf = 0.0;

    // -------- Update-11: go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // add the power factor value to the total
        sum_pf += samples[i].powerFactor;
    }

    // -------- Update-11: return the mean power factor value
    // divide by the number of samples
    return sum_pf / count;
}
double mean_THD(WaveformSample *samples, size_t count) {
    // -------- Update-12: store the total of THD values
    double sum_thd = 0.0;

    // -------- Update-12: go through every waveform sample
    for (size_t i = 0; i < count; i++) {

        // add the THD value to the total
        sum_thd += samples[i].thd;
    }

    // -------- Update-12: return the mean THD value
    // divide by the number of samples
    return sum_thd / count;
}
