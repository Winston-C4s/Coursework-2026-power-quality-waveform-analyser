#ifndef IO_H
#define IO_H

#include <stddef.h>
#include "waveform.h"


// ----------- Update-3: CSV File Loading(declare the function used to load waveform data from a CSV file)

WaveformSample *load_csv_data(const char *filename, size_t *count);

#endif
