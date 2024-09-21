#ifndef FILE_READER_H
#define FILE_READER_H

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

struct TextFile{
    char *buff;
    int size;
    int stringCount;
    char **stringPointers;
};

enum fileErrorType {
    NO_ERROR,
    ERROR_FAILED_TO_OPEN_FILE,
    ERROR_FAILED_TO_READ_FILE_STATS,
    ERROR_FAILED_TO_CALLOC
};

fileErrorType readTextBuffer(TextFile *textFile, const char *filename);

fileErrorType printTextInFile(const TextFile *textFile, const char *filename);

#endif