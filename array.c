#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "array.h"

struct array {
    node_t **F;
    int size;
    int n;
};

// Creates an empty array with inital size of 2 
// Credit / Reference to Workshop 3.7 / 3.8 
array_t *createArray() {
    array_t *arr = malloc(sizeof(*arr));
    assert(arr);
    int size = INIT_SIZE;
    arr->size = size;
    arr->F = malloc(size * sizeof(*(arr->F)));
    assert(arr->F);
    arr->n = 0;
    return arr;
}

// Ensures an array has enough 'space' so we can insert another element
// Credit / Reference to Workshop 3.7 / 3.8
void ensureArraySize(array_t *arr) {
    if(arr->n == arr->size) {
        arr->size *= 2;
        arr->F = realloc(arr->F, arr->size * sizeof(*(arr->F)));
        assert(arr->F);
    }
}

// Add a node_t *n to the end of an array
// Inspired by Workshop 3.7 / 3.8
void appendArray(array_t *arr, node_t *n) {
    ensureArraySize(arr);
    arr->F[arr->n] = n;
    (arr->n)++;
}

// Ensures the size of an array and performs an insertion sort based on grade1in attribue
// Credit / Reference to Workshop 3.7 / 3.8
void arraySortInsert(array_t *arr, node_t *n) {
    int i;
    ensureArraySize(arr);
    for (i = arr->n - 1; i >=0 && footpathGetGradelin(n) < footpathGetGradelin(arr->F[i]); i--) {
        arr->F[i + 1] = arr->F[i];
    }
    arr->F[i + 1] = n;
    arr->n++;
}


// Shrinks the size of an array to the number of elements left in the array
// Credit / Refrence to Workshop 3.7 / 3.8
void arrayShrink(array_t *arr) {
	if (arr->size != arr->n) {
		arr->size = (arr->n > 2) ? arr->n : 2;
		arr->F = realloc(arr->F, arr->size * sizeof(*(arr->F)));
		assert(arr->F);
	}
}

// Takes a list and creates an array that has pointers to nodes sorted 
// based on the grade1in attribute
array_t *getFootpathArray(list_t *footpaths) {
    // Create an empty array
    array_t *footpathArray = createArray();
    // Loop through elements of the lined list
    node_t *current = footpaths->head;
    while (current) {
        arraySortInsert(footpathArray, current); // Insert each node into the array
        current = current->next;
    } 
    arrayShrink(footpathArray);
    return footpathArray;
}
// Takes a query of a grade1lin attribue and returns the node that is closet
// i.e lowest difference of query and nodes of the array
node_t *searchGradelin(array_t *arr, double query, FILE *output) {
    double min = ARB_MIN;
    node_t *tmp;
    int mid;
    int lo = 0;
    int hi = arr->n - 1;
    while (lo<=hi) {
        mid = (lo + hi) / 2;
        // calculuate difference and find the min value
        double cmp = query - footpathGetGradelin(arr->F[mid]);
        if (fabs(cmp) < min) {
            min = fabs(cmp);
            tmp = arr->F[mid];
        }
        if (cmp < 0) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return tmp;
}

// Reads in values from stdin and processes data 
void searchArrayGradelin(array_t *arr, FILE *output) {
    char *line = NULL;
    size_t lineBufferLength = 0;
    int c;
    // Scan line
    while((c = getline(&line, &lineBufferLength, stdin)) > 0) {
        // Since 
        if (line[c-1] == '\n') line[c - 1] = '\0';
        // Parse line into double
        double query;
        sscanf(line,"%lf", &query);
        // Search the array for the given query
        node_t *footpath = searchGradelin(arr, query, output);
        // Print and process data
        fprintf(output, "%s\n", line);
        printFootpathOutput(footpath->data, output);
        printf("%s --> %.1lf\n", line, footpathGetGradelin(footpath));
    }
}
// Free the array
// Credit / Refrence to Workshop 3.7 / 3.8
void arrayFree(array_t *arr) {
	for (int i = 0; i < arr->n; i++) {
		free(arr->F[i]);
	}
	free(arr->F);
	free(arr);
}

