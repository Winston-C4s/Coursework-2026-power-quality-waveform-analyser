#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stddef.h>

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

// a function to calculate RMS for phase A voltage
double calculate_rms_A(WaveformSample *samples, size_t count);

#endif
