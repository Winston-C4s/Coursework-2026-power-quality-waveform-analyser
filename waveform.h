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

// ----------- Update-5: Phase A RMS Value Calculation
// To declare the function use to calculate RMS for phase A voltage
double rms_A(WaveformSample *samples, size_t count);
// ----------- Update-6: Phase A Peak-to-Peak Value Calculation
double peak_to_peak_A(WaveformSample *samples, size_t count);
// ----------- Update-7: Phase A DC Offset Value Calculation
double DC_offset_A(WaveformSample *samples, size_t count);
//----------- Update-8: clipping detection for phase A
int clipping_detection_A(WaveformSample *samples, size_t count);
//----------- Update-9: compliance check for phase A
int compliance_check_A(WaveformSample *samples, size_t count);
#endif
