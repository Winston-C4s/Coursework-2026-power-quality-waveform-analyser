cmake_minimum_required(VERSION 3.20)

project(PowerQualityWaveformAnalyser C)

set(CMAKE_C_STANDARD 11)

add_executable(PowerQualityWaveformAnalyser
    main.c
    io.c
    waveform.c
)

target_link_libraries(PowerQualityWaveformAnalyser m)