#include "fileReader.h"

fileErrorType readTextBuffer(TextFile *textFile, const char *filename){
    struct stat sb;
    if (stat(filename, &sb) == -1) 
        return ERROR_FAILED_TO_READ_FILE_STATS;
    textFile->size = sb.st_size;
    textFile->buff = (char*)calloc(textFile->size + 2, sizeof(char));
    if (textFile->buff == NULL) return ERROR_FAILED_TO_CALLOC;

    FILE *ptr = fopen(filename, "rb");
    if (ptr == NULL) return ERROR_FAILED_TO_OPEN_FILE; // fclose
    fread(textFile->buff + 1, sizeof(char), textFile->size, ptr); // FIXME: 
    fclose(ptr);
    // А вообще я бы разделил эту функцию на 2
    // 1) Считать файл в буфер (очень полезная, еще 1000 раз пригодится)
    // 2) Из буфера сделать массив указателей 
    textFile->stringCount = 0;
    for (int i = 1; i <= textFile->size; ++i) {
        if (textFile->buff[i] == '\r' || textFile->buff[i] == '\n'){
            textFile->buff[i] = '\0';
        } else if (textFile->buff[i - 1] == '\0') ++textFile->stringCount;
    }
    textFile->stringPointers = (char**)calloc(textFile->stringCount, sizeof(char*));
    if (textFile->stringPointers == NULL) return ERROR_FAILED_TO_CALLOC; // free()
    int x = 0;
    for (int i = 1; i <= textFile->size; ++i) {
        if (textFile->buff[i] != '\0' && textFile->buff[i - 1] == '\0'){
            textFile->stringPointers[x++] = &textFile->buff[i];
        }
    }
    return NO_ERROR;
}

fileErrorType printTextInFile(const TextFile *textFile, const char *filename){
    FILE *ptr = fopen(filename, "w");
    if (ptr == NULL) return ERROR_FAILED_TO_OPEN_FILE;
    for (int i = 0; i < textFile->stringCount; ++i) {
        fputs(textFile->stringPointers[i], ptr);
        putc('\n', ptr);
    }
    fclose(ptr);
    return NO_ERROR;
}
