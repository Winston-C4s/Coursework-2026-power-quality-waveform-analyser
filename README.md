# Coursework-2026-power-quality-waveform-analyser-
C coursework project for analysing 3 phase power quality waveform data
4/4 I'll Initial project setup with README, CMakeLists, and source file structure

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
Current Status
- CSV loading implemented
- Three-phase voltage analysis implemented
- RMS, peak-to-peak, DC offset, clipping, and compliance implemented
- Mean frequency, mean power factor, and mean THD implemented
- Results written to results.txt
- Development log included

#Future Work
- Add waveform analysis (RMS, frequency, etc.)
- Improve the robustness of CSV file parsing
- Visualization or other processing

#How it Works
1. The program takes a CSV file name as input from the command line
2. The file is read using `load_csv_data()`
3. The Data is stored as an array of `WaveformSample`
4. The first few samples are printed to verify correctness
5. Allocated memory is freed before the program exits

# Future Work
- Add waveform analysis (RMS, frequency)
- Add more advanced processing or visualisation
- Implement RMS calculation
- Add peak-to-peak analysis
- Detect DC offset
- Implement clipping detection

-how to run?
gcc Main.c io.c waveform.c -o analyser.exe -lm
.\analyser.exe power_quality_log.csv
