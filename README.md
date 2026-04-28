# Coursework 2026 Power Quality Waveform Analyser
C coursework project for analysing 3 phase power quality waveform data

#Overview
This project is a C-language application for analyzing three-phase power quality waveform data from a CSV file.
The program loads waveform samples and displays basic information to verify that the data was loaded correctly.

#Features
- Load waveform data from CSV files
- Compute RMS voltage for phases A, B, and C
- Compute peak-to-peak voltage for phases A, B, and C
- Compute DC offset for phases A, B, and C
- Detect clipping events for phases A, B, and C
- Check voltage compliance for phases A, B, and C
- Compute mean frequency
- Compute mean power factor
- Compute mean THD
- Write a structured plain-text report to results.txt

#Project Structure
- `Main.c` – Program entry point
- `io.c / io.h` – Handle CSV file reading
- `waveform.c / waveform.h` – Define waveform data structure
- `CMakeLists.txt` – Build configuration
- `development_log.md` – Development progress tracking

#Current Status
- CSV loading implemented
- Three-phase voltage analysis implemented
- RMS, peak-to-peak, DC offset, clipping, and compliance implemented
- Mean frequency, mean power factor, and mean THD implemented
- Results written to results.txt
- Development log included

#How it Works
1. The program takes a CSV file name as input from the command line
2. The file is read using `load_csv_data()`
3. The data is stored as an array of `WaveformSample`
4. The program computes waveform analysis results for the three phases
5. The results are displayed in the terminal
6. The results are written to `results.txt`
7. Allocated memory is freed before the program exits

## Future Work
- Improve the robustness of CSV file parsing
- Add extra validation for invalid or empty input files
- Improve report formatting further
- Add standard deviation as an extension feature
- Add visualisation or further waveform processing

-how to run?
gcc Main.c io.c waveform.c -o analyser.exe -lm

.\analyser.exe power_quality_log.csv
