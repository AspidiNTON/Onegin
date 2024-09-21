#include "sorter.h"


// В стандартной библиотеке Си есть bsearch, можно было сделать их совместимыми)
/*int binarySearch(void *base, void *elem, size_t elemSize, int l, int r, compareFunction comparator) {
    
    while (l < r) {
        size_t m = l + (r - l) / 2;
        if ((*comparator)((char*)base + m * elemSize, (char*)elem)) l = m + 1;
        else                                                        r = m;
    }
    return l;
}*/

/*void assign(void *f, void *s, size_t elemSize) {
    char* x = (char*)f;
    char* y = (char*)s;
    for (size_t i = 0; i < elemSize; ++i) {
        *(x + i) = *(y + i);
    }
}*/

// void assign(void*, void*, size_t elemSize);
// vectorize: unsigned long long
//              8 - 4 - 2 - 1


// Проси последним элементом workspace
/*void sort(void *base, size_t n, size_t elemSize, compareFunction comparator){
    int i, loc, j;
    void *s = calloc(elemSize, sizeof(char));
    for (i = 1; i < (int)n; ++i) {
        j = i - 1;
        for (int k = 0; k < (int)elemSize; ++k) *((char*)s + k) = *((char*)base + i * elemSize + k);

        loc = binarySearch(base, s, elemSize, 0, i, comparator);

        while (j >= loc) {
            assign((char*)base + (j + 1) * elemSize, (char*)base + j * elemSize, elemSize);
            --j;
        }
        assign((char*)base + (j + 1) * elemSize, (char*)s, elemSize);
    }
}*/

void swap(void *f, void *s, size_t elemSize){
    int64_t* x = (int64_t*)f;
    int64_t* y = (int64_t*)s;
    int64_t tmp;
    while (elemSize >= 8) {
        tmp = *x;
        *x = *y;
        *y = tmp;
        ++x, ++y;
        elemSize -= 8;
    }
    char* l = (char*)x;
    char* r = (char*)y;
    char t;
    while (elemSize > 0) {
        t = *l;
        *l = *r;
        *r = t;
        ++l, ++r;
        --elemSize;
    }
}

int partition(void *base, int begin, int end, size_t elemSize, compareFunction comparator) {
    int i = begin, j = end;
    char* p = (char*)base + begin * elemSize;
    while (i < j) {
        while ((*comparator)(((char*)base + i * elemSize), p) && i <= end - 1) ++i;
        while (!(*comparator)((char*)base + j * elemSize, p) && j >= begin + 1) --j;
        if (i < j) swap((char*)base + i * elemSize, (char*)base + j * elemSize, elemSize);
    }
    swap((char*)base + begin * elemSize, (char*)base + j * elemSize, elemSize);
    return j;
}

void quickSort(void *base, int begin, int end, size_t elemSize, compareFunction comparator) {
    if (begin < end) {
        int pi = partition(base, begin, end, elemSize, comparator);
        quickSort(base, begin, pi - 1, elemSize, comparator);
        quickSort(base, pi + 1, end, elemSize, comparator);
    }
}

bool stringComparator(void *f, void *s){
    char *x = *(char**)f;
    char *y = *(char**)s;
    while (*x != '\0' && *y != '\0') {
        while (*x != '\0' && !isalpha(*x)) ++x;
        if (*x == '\0') break;
        while (*y != '\0' && !isalpha(*y)) ++y;
        if (*y == '\0') break;
        if (tolower(*x) == tolower(*y)) {
            ++x;
            ++y;
            continue;
        }
        if (tolower(*x) < tolower(*y)) return true;
        else return false;
    }
    if (*x == '\0' && *y == '\0') return false;
    if (*x == '\0') return true;
    else return false;
}

bool reverseStringComparator(void *f, void *s){
    char *x = *(char**)f;
    char *y = *(char**)s;
    while (*x != '\0') ++x;
    --x;
    while (*y != '\0') ++y;
    --y;
    while (*x != '\0' && *y != '\0') {
        while (*x != '\0' && !isalpha(*x)) --x;
        if (*x == '\0') break;
        while (*y != '\0' && !isalpha(*y)) --y;
        if (*y == '\0') break;
        if (tolower(*x) == tolower(*y)) {
            --x;
            --y;
            continue;
        }
        if (tolower(*x) < tolower(*y)) return true;
        else return false;
    }
    if (*x == '\0' && *y == '\0') return false;
    if (*x == '\0') return true;
    else return false;
}

bool intComp(void *f, void *s){
    int x = *(int*)f;
    int y = *(int*)s;
    return x < y;
}
