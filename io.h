#ifndef IO_H
#define IO_H

#include <stddef.h>
#include "waveform.h"

WaveformSample *load_csv_data(const char *filename, size_t *count);

#endif