# Coursework-2026-power-quality-waveform-analyser-
C coursework project for analysing 3 phase power quality waveform data
4/4 I'll Initial project setup with README, CMakeLists, and source file structure

#Overview
This project is a C-language application for analyzing three-phase power quality waveform data from a CSV file.
The program loads waveform samples and displays basic information to verify that the data was loaded correctly.

#Features
- Load waveform data from CSV files
- Store data using structured data types
- Display example values ​​(time and voltage)
- Basic error handling for file input

#Project Structure
- `Main.c` – Program entry point
- `io.c / io.h` – Handle CSV file reading
- `waveform.c / waveform.h` – Define waveform data structure
- `CMakeLists.txt` – Build configuration
- `development_log.md` – Development progress tracking

#Current Status
Initial version complete:
- Implemented CSV file loading
- Example output works correctly
- Code includes detailed comments for easy learning and explanation

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
