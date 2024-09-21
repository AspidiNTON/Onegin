#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>

int myPuts(const char *s);

char *myStrchr(const char *s, int c);

size_t myStrlen(const char *s);

char *myStrcpy(char *to, char *from);

char *myStrncpy(char *to, char *from, int n);

char *myStrcat(char *s, const char *t);

char *myStrncat(char *s, const char *t, int n);

char *myFgets(char *s, int n, FILE *stream);

char *myStrdup(char *s);

int myGetline(char *s, int n);

int fileGetline(char *s, int n, FILE *stream);

//bool stringComp(char *f, char *s);

#endif