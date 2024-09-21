#include <stdlib.h>

#include "flags.h"

const Flag flagsQuad[] {
    {"-h", "--help", "shows avalible commands", printHelp},
    {"-i", "--input", "name of the input file to sort after the flag", setInputFilename},
    {"-o", "--output", "name of the output file after the flag", setOutputFilename},
    {"-r", "--reverse", "reverse string sorting", setReverseSorting}
};

int main(int argc, const char *argv[]) {
    int flagsSize = sizeof(flagsQuad) / sizeof(Flag);
    FileFlagData fileFlagData = {};
    if (checkFlags(argc, argv, flagsSize, flagsQuad, &fileFlagData) != 0) return 0;

    TextFile onegin = {};
    fileErrorType err = readTextBuffer(&onegin, fileFlagData.inputFilename);
    switch(err){
        case ERROR_FAILED_TO_READ_FILE_STATS:
            printf("Failed to read %s file stats\n", fileFlagData.inputFilename);
            return 0;
        case ERROR_FAILED_TO_CALLOC:
            printf("Failed to allocate buffer\n");
            return 0;
        case ERROR_FAILED_TO_OPEN_FILE:
            printf("Failed to open %s\n", fileFlagData.inputFilename);
            return 0;
        default:
            break;
    }

    quickSort(onegin.stringPointers, 0, onegin.stringCount - 1, sizeof(char*), 
         fileFlagData.isReverse ? reverseStringComparator : stringComparator);

    if (printTextInFile(&onegin, fileFlagData.outputFilename) == ERROR_FAILED_TO_OPEN_FILE) {
        printf("Failed to open %s\n", fileFlagData.outputFilename);
        return 0;
    }
    return 0;
}
