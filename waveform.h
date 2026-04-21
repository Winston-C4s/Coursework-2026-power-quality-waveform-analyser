#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stddef.h>

// ----------- Update-2: Waveform Data Structure
// this struct stores one row of waveform data from the CSV file
typedef struct {
    double time;
    double voltageA;
    double voltageB;
    double voltageC;
    double current;
    double frequency;
    double powerFactor;
    double thd;
} WaveformSample;

// ----------- Update-5: RMS Value Calculation
// To declare the function use to calculate RMS voltage
double rms(WaveformSample *samples, size_t count, char phase);
// ----------- Update-6: Peak-to-Peak Value Calculation
double peak_to_peak(WaveformSample *samples, size_t count, char phase);
// ----------- Update-7: DC Offset Value Calculation
double DC_offset(WaveformSample *samples, size_t count, char phase);
//----------- Update-8: clipping detection
int clipping_detection(WaveformSample *samples, size_t count, char phase);
//----------- Update-9: compliance check
int compliance_check(WaveformSample *samples, size_t count, char phase);
//----------- update-10: mean frequency analysis
double mean_frequency(WaveformSample *samples, size_t count);
//----------- Update-11: mean power factor analysis 
double mean_power_factor(WaveformSample *samples, size_t count);
//----------- Update-12: mean THD analysis 
double mean_THD(WaveformSample *samples, size_t count);
//----------- Update-13: Phase B and C analysis functions
double get_phase_voltage(WaveformSample sample, char phase);
#endif
