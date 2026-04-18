Development Log for Software Design: Power Quality Waveform Analyser
Project Title: Power Quality Waveform Analyser
Date Started: April 4, 2026
Development Period: Ongoing
Author: Winston Lin(Yu ting)

________________________________________
1. Structure Chart


2. Program Design (Pseudocode/Flowcharts)
3. CSV file
load file
save to struct array
Analysis of three-phase voltage
Print the analysis results and write them to results.txt
Main Program Flowchart
   ↓
Get command-line argument
   ↓
(Was a CSV filename provided?)
   ├─ if No → Print usage message→ End
   └─ if Yes
         ↓
     Load CSV data
         ↓
     (Did loading succeed?)
         ├─ if No → Print error message → End
         └─ if Yes
               ↓
           Compute RMS
               ↓
           Compute Peak-to-Peak
               ↓
           Compute DC Offset
               ↓
           Count Clipped Samples
               ↓
           Check Compliance
               ↓
           Write results to results.txt
               ↓
           Free allocated memory
               ↓
             End

4. Function Description

5. Evidence of Unit Testing


6. Evidence of Integration Testing



7. Evidence of Version Control
# Update 1 – Project Setup
In this update, I've set up the initial project structure

# Goal
To establish the basic structure for the waveform analysis program

# Implementation
- Create initial files: Main.c, io.c, io.h, waveform.h, waveform.c
- Add a README file
- Organize the project into modules

# Update 2 – Waveform Data Structure
In this update, I defined a data structure for storing waveform samples

# Goal
To represent each row of CSV data in a structured way

# Implementation
- A `WaveformSample` structure was created in waveform.h
- It contains fields such as time, voltageA, voltageB, voltageC, current, frequency, powerFactor, and thd

# Update 3 – CSV File Loading
In this update, I try to load the CSV file reading functionality

# Objective
To load waveform data from a CSV file into memory

# Implementation
- Implemented `load_csv_data()` in io.c
- Used `fopen`, `fgets`, and `sscanf` to read and parse the file
- Stored data into a dynamically allocated array of WaveformSample

# Update 4 – Display Loaded Data
In this update, I created the main program flow and displayed sample data to make sure the data is shown in the terminal

# Objective
To verify that the CSV data is correctly loaded

# Implementation
- Called `load_csv_data()` in Main.c
- Printed the number of samples loaded
- Displayed the first few waveform samples
  
# Update 5 – Phase A RMS Value Calculation
Attempted to calculate the RMS value of phase A voltage

# Objective
The objective of this update is to begin analyzing waveform data

# Formula Used
The root mean square (RMS) value is calculated using the following formula:
RMS = sqrt( (1/N) * Σ(V²) )

Where:
- V = The value of voltage samples
- N = Number of samples

# Code Explanation
This function iterates through all samples:
- Squares each voltage value
- Adds them together
- Divides by the total number of samples
- Takes the square root using the `sqrt()` function in `<math.h>`

# Results
- Number of loaded sample points
- Phase A RMS voltage
- First few waveform sample points used for verification
- The calculated RMS value is around 229.81 V, which is close to the expected value of 230 V 

Future improvements will include:
- Calculating the RMS values ​​of phases B and C
- Peak-to-peak voltage
- DC offset calculation

# Update 6 – Phase A Peak-to-Peak Calculation

In this update, I implemented the peak-to-peak calculation for phase A voltage.

# Objective
To measure the full voltage range of the waveform from the highest point to the lowest point.

# Implementation
- Added `peak_to_peak_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c` and printed the result

# Formula Used
Peak-to-Peak = Vmax - Vmin

Where:
- Vmax = maximum voltage value
- Vmin = minimum voltage value

# Code Explanation
The function loops through all waveform samples:
- compares each phase A voltage value
- updates the maximum voltage if a larger value is found
- updates the minimum voltage if a smaller value is found
- returns the difference between the maximum and minimum values

# Results
- Peak-to-Peak Voltage A: 650.00 V
- This result is close to the expected value for a 230 V RMS waveform

# Implementation
- Added a new function `calculate_rms_A()` to `waveform.c`
- Declared a new function in `waveform.h` for use in other files
- Called the function in `Main.c` and printed the results

# Update 7 – Phase A DC Offset Calculation

In this update, I added the DC offset calculation for phase A voltage

# Objective
The goal of this step was to check whether the waveform is centred around zero, or if it is shifted slightly up or down.

# Implementation
- Added `dc_offset_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c`
- Printed the result in the terminal

# Formula Used
DC Offset = (1/N) × Σ(V)

Where:
- V = voltage value
- N = number of samples

# Code Explanation
The function goes through all phase A voltage samples, adds them together, and then divides the total by the number of samples. This gives the average voltage value, which is the DC offset.

# Results
The DC offset for phase A was printed in the terminal
The result should be close to 0 V for a normal AC waveform

# Update 8 – Phase A Clipping Detection

In this update, I implemented clipping detection for phase A voltage.

# Objective
To count how many waveform samples reach the clipping threshold.

# Implementation
- Added `clipping_detection_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c` and displayed the result

# Rule Used
A sample is counted as clipped when: |V| ≥ 324.9 V

# Code Explanation
The function loops through all phase A voltage samples and checks whether the voltage reaches or exceeds the clipping threshold. If it does, the counter increases by one. The function then returns the total number of clipped samples.

# Results
- Clipping count A was displayed in the terminal
- The program reported 20 clipped samples for phase A

# Update 9 – Phase A Compliance Check

In this update, I added a compliance check for phase A.

# Objective
The aim was to check whether the RMS voltage of phase A falls inside the normal standard range.

# Implementation
- Added `compliance_check_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c`
- Displayed the result in the terminal

# Rule Used
A phase passes the compliance check if:

207 V ≤ VRMS ≤ 253 V

# Code Explanation
The function uses the RMS result of phase A and checks whether it is inside the valid range.
If it is inside the range, the function returns `1`.
If not, it returns `0`.

# Results
The program showed that phase A is compliant with standards

# Update 10 – Mean Frequency Calculation

In this update, I added the mean frequency calculation for the waveform data.

# Objective
The aim of this step was to calculate the average frequency of the loaded waveform samples.

# Implementation
- Added `mean_frequency_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c`
- Printed the mean frequency in the terminal

# Formula Used
Mean Frequency = (1/N) × Σ(f)

Where:
- f = frequency value
- N = number of samples

# Code Explanation
The function goes through all waveform samples, adds all frequency values together, and divides the total by the number of samples. This gives the average frequency of the dataset.

# Results
- Mean Frequency A: 50.03 Hz
- This result is within the expected range for the dataset

# Update 11 – Mean Power Factor Calculation

In this update, I added the mean power factor calculation for the waveform data.

# Objective
The aim of this step was to calculate the average power factor of the loaded waveform samples.

# Implementation
- Added `mean_power_factor_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c`
- Printed the mean power factor in the terminal

# Formula Used
Mean Power Factor = (1/N) × Σ(PF)

Where:
- PF = power factor value
- N = number of samples

# Code Explanation
The function goes through all waveform samples, adds all power factor values together, and divides the total by the number of samples. This gives the average power factor of the dataset.

# Results
- Mean Power Factor A: 0.96
- This result is within the expected range for the dataset

# Update 12 – Mean THD Calculation

In this update, I added the mean THD calculation for the waveform data.

# Objective
The aim of this step was to calculate the average total harmonic distortion (THD) of the loaded waveform samples.

# Implementation
- Added `mean_thd_A()` in `waveform.c`
- Declared the function in `waveform.h`
- Called the function in `Main.c`
- Printed the mean THD result in the terminal

# Formula Used
Mean THD = (1/N) × Σ(THD)

Where:
- THD = total harmonic distortion value
- N = number of samples

# Code Explanation
The function goes through all waveform samples, adds all THD values together, and divides the total by the number of samples. This gives the average THD of the dataset.

# Results
- Mean THD A: 2.09%

10. References
