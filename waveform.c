#include <math.h>
#include "waveform.h"

double calculate_rms_A(WaveformSample *samples, size_t count) {
    double sum_sq = 0.0;

    for (size_t i = 0; i < count; i++) {
        sum_sq += samples[i].voltageA * samples[i].voltageA;
    }

    return sqrt(sum_sq / count);
}
