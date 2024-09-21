#ifndef FLAGS_H
#define FLAGS_H

#include <string.h>
#include <stdio.h>

#include "fileReader.h"
#include "sorter.h"
//#include "colorPrint.h"



struct FileFlagData {
    bool isReverse = false;
    char inputFilename[80] = "input.txt";
    char outputFilename[80] = "output.txt";
};

struct Flag {
    const char* shortName;
    const char* fullName;
    const char* description;
    int (*flagFunction)(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argnum);
};

int printHelp(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argnum);

int setInputFilename(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum);

int setOutputFilename(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum);

int setReverseSorting(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum);

int checkFlags(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData);

#endif