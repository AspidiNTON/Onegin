#include "flags.h"


int printHelp(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum){
    for (int j = 0; j < flagsSize; ++j) {
        printf("%s %s: %s\n", flags[j].shortName, flags[j].fullName, flags[j].description);
    }
    return 1;
}

int setInputFilename(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum){
    if (*argNum + 1 < argc) {
        ++(*argNum);
        strncpy(fileFlagData->inputFilename, argv[*argNum], 80);
    } else {
        printf("No input filename provided\n");
        return 2;
    }
    return 0;
}

int setOutputFilename(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum){
    if (*argNum + 1 < argc) {
        ++(*argNum);
        strncpy(fileFlagData->outputFilename, argv[*argNum], 80);
    } else {
        printf("No output filename provided\n");
        return 2;
    }
    return 0;
}

int setReverseSorting(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData, int *argNum){
    fileFlagData->isReverse = true;
    return 0;
}

bool compareFlag(const char * s, const Flag *flag) {
    return strcmp(s, flag->fullName) == 0 || strcmp(s, flag->shortName) == 0;
}

int checkFlags(int argc, const char *argv[], int flagsSize, const Flag* flags, FileFlagData *fileFlagData){
    for (int i = 1; i < argc; ++i) {
        bool f = true;
        for (int j = 0; j < flagsSize; ++j) {
            if (compareFlag(argv[i], &flags[j])) {
                if (flags[j].flagFunction(argc, argv, flagsSize, flags, fileFlagData, &i) != 0) return 1;
                f = false;
                break;
            }
        }
        if (f) {
            printf("Unknown Flag: %s\n", argv[i]);
            return 2;
        }
    }
    return 0;
}