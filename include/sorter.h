#ifndef SORTER_H
#define SORTER_H

#include <stdlib.h>
#include <ctype.h>
#include <cstdint>
#include <stdio.h>

typedef bool (*compareFunction)(void* f, void* s);

int binarySearch(void *base, void *elem, size_t elemSize, int l, int r, compareFunction comporator);

void assign(void *f, void *s, size_t elemSize);

void sort(void *base, size_t n, size_t elemSize, compareFunction comporator);

void swap(void *f, void *s, size_t elemSize);

int partition(void *base, int begin, int end, size_t elemSize, compareFunction comporator);

void quickSort(void *base, int begin, int end, size_t elemSize, compareFunction comporator);

bool stringComparator(void *f, void *s);

bool reverseStringComparator(void *f, void *s);

bool intComp(void *f, void *s);

#endif