#pragma once

#include <string>

// Print useful information to the default output. Same usage as with printf
void LogInfo(const char* str, ...);

void LogInfo(std::string);

// Print error notification to the default output. Same usage as with printf
void LogError(const char* str, ...);


// Read OpenCL source code from fileName and store it in source. The number of read bytes returns in sourceSize
int ReadSourceFromFile(const char* fileName, char** source, size_t* sourceSize);