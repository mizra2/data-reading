#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "list.h"
#include "data.h"

#define INIT_SIZE 2;
#define ARB_MIN 1000000

typedef struct array array_t;

array_t *createArray();

void ensureArraySize(array_t *arr);

void appendArray(array_t *arr, node_t *n);

void arraySortInsert(array_t *arr, node_t *n);

array_t *getFootpathArray(list_t *footpaths);

void arrayShrink(array_t *arr);

void searchArrayGradelin(array_t *arr, FILE *output);

node_t *searchGradelin(array_t *arr, double query, FILE *output); 

void arrayFree(array_t *arr);

#endif


