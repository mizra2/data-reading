/*           Data Reading
 *        Written by: Milad Izra
 * 
 * Special Thanks / Credit to "Anh Vo" for assistance 
 *          
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"
#include "list.h"
#include "array.h"
#define MAX_LINE_LENGTH 512
#define ADDRESS_SEARCH 1
#define GRADELIN_SEARCH 2

int processDataQuery(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    FILE *inFile = fopen(argv[2], "r");
    FILE *outFile = fopen(argv[3], "w");
    list_t *footpaths = make_empty_list();
    buildFootpathList(inFile, footpaths);
    int queryType = processDataQuery(argc, argv);
    // runs respective query system
    switch (queryType) {
        case ADDRESS_SEARCH: 
            searchDictList(footpaths, outFile);
            freeFootpath(footpaths);
            break;
        case GRADELIN_SEARCH: ;
            array_t *sortedArray = getFootpathArray(footpaths);
            searchArrayGradelin(sortedArray, outFile);
            arrayFree(sortedArray);
            break;
        default:
            exit(EXIT_FAILURE);
    }
    fclose(inFile);
    fclose(outFile);
    return 0;
}

int processDataQuery(int argc, char *argv[]) {
    return atoi(argv[1]);
}

