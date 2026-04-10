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

#Objective
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

# Implementation
- Added a new function `calculate_rms_A()` to `waveform.c`
- Declared a new function in `waveform.h` for use in other files
- Called the function in `Main.c` and printed the results

# Formula Used
The root mean square (RMS) value is calculated using the following formula:
RMS = sqrt( (1/N) * Σ(V²) )

Where:
- V = The value of voltage samples
- N = Number of samples

#Code Explanation
This function iterates through all samples:
- Squares each voltage value
- Adds them together
- Divides by the total number of samples
- Takes the square root using the `sqrt()` function in `<math.h>`

#Results
- Number of loaded sample points
- Phase A RMS voltage
- First few waveform sample points used for verification
- The calculated RMS value is around 229.81 V, which is close to the expected value of 230 V 

Future improvements will include:
- Calculating the RMS values ​​of phases B and C
- Peak-to-peak voltage
- DC offset calculation

9. Full Code (in Zip File) uploaded externally to Blackboard on:

10. References
