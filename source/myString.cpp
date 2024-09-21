#include "myString.h"

int myPuts(const char *s){
    int i = 0;
    while (s[i] != '\0') {
        if (putchar(s[i]) == EOF) return EOF;
        ++i;
    }
    if (putchar('\n') == EOF) return EOF;
    return 1;
}

char *myStrchr(const char *s, int c){
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == c) return (char*)(s + i);
        ++i;
    }
    return NULL;
}

size_t myStrlen(const char *s){
    size_t i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

char *myStrcpy(char *to, char *from){
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
    return to;
}

char *myStrncpy(char *to, char *from, int n){
    int i = 0;
    while (from[i] != '\0' && i < n) {
        to[i] = from[i];
        ++i;
    }
    if (i < n) to[i] = '\0';
    return to;
}

char *myStrcat(char *s, const char *t){
    int i = 0;
    while (s[i] != '\0') ++i;
    while ((s[i++] = *t) != '\0') ++t;
    return s;
}

char *myStrncat(char *s, const char *t, int n){
    int i = 0;
    while (s[i] != '\0') ++i;
    n += i + 1;
    while (i < n - 1 && (s[i++] = *t) != '\0') ++t;
    s[i] = '\0';
    return s;
}

char *myFgets(char *s, int n, FILE *stream){
    int i = 0, x;
    while (i < n - 1 && (x = getc(stream)) != EOF) {
        s[i++] = x;
        if (x == '\n') break;
    }
    s[i] = '\0';
    return s;
}

char *myStrdup(char *s){
    size_t n = myStrlen(s);
    char* p = (char*)calloc(n + 1, sizeof(char));
    for (size_t i = 0; i < n; ++i) p[i] = s[i];
    return p;
}

int myGetline(char *s, int n)
{
    int i = 0, x;
    while (i < n - 1 && (x = getchar()) != EOF && x != '\n') s[i++] = x;
    s[i] = '\0';
    return i;
}

int fileGetline(char *s, int n, FILE *stream){
    int i = 0, x;
    while (i < n - 1 && (x = getc(stream)) != EOF && x != '\n') {
        s[i++] = x;
    }
    s[i] = '\0';
    if ((x = getc(stream)) == EOF && i == 0) return EOF;
    return 0;
}

/*bool stringComp(char *f, char *s){
    while (*f != '\0' && *s != '\0') {
        while (*f != '\0' && (*f < 'a' || *f > 'z') && (*f < 'A' || *f > 'Z')) ++f;
        if (*f == '\0') break;
        while (*s != '\0' && (*s < 'a' || *s > 'z') && (*s < 'A' || *s > 'Z')) ++s;
        if (*s == '\0') break;
        if (*f == *s) {
            ++f;
            ++s;
            continue;
        }
        if (*f < *s) return true;
        else return false;
    }
    if (*f == '\0' && *s == '\0') return false;
    if (*f == '\0') return true;
    else return false;
}*/