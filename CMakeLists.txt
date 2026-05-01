cmake_minimum_required(VERSION 3.10)
project(PowerQualityWaveformAnalyser C)

# Set C standard to C99 (course requirement)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable compiler warnings for code quality
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Create the executable
add_executable(analyser
    main.c
    io.c
    waveform.c
)

# Link the math library
target_link_libraries(analyser m)
