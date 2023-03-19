#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

// Create an empty list  and returns a pointer to that list
list_t
*make_empty_list() {
	list_t *list = (list_t*)malloc(sizeof(*list));
	assert(list!=NULL);
	list->head = list->tail = NULL;
	return list;
}

// Adds a footpath struct to end of a linked list
// Inspired by Workshop 4 and listops.c from PPSAA
list_t
*appendFootpath(list_t *list, footpath_t *value) {
	node_t *new;
	new = (node_t*)malloc(sizeof(*new));
	assert(list!=NULL && new!=NULL);
	new->data = value;
	new->next = NULL;
	if (list->tail==NULL) {
		list->head = list->tail = new;
	} else {
		list->tail->next = new;
		list->tail = new;
	}
	return list;
}

// Reads a line, creates a struct and stores it into a footpath list
int
buildFootpathList(FILE *f, list_t *footpathList) {
	int n = 0;
	footpath_t *footpath;
	footpathSkipHeaderLine(f);
	while((footpath = readFootpath(f)) != NULL) {
        appendFootpath(footpathList, footpath);
        n++;
    }
    free(footpath);
	return n;
}

// Searchs a linked list given a string query and returns
// It's number of occurenances and prints out that occurance
int searchFootpath(list_t *footpath, char *query, FILE *output) {
    node_t *current = footpath->head;
    int i = 0;
    fprintf(output, "%s\n", query);
    while(current){
        if (!strcmp(current->data->address, query)) {
            i++;
            printFootpathOutput(current->data, output);
        }
        current = current->next;
    }
    return i;
}

// Reads a query from stdin line by line and processes if it 
// in the linked list
void searchDictList(list_t *footpath, FILE *output) {
    char *line = NULL;
    size_t lineBufferLength = 0;
    int c;
    while((c = getline(&line, &lineBufferLength, stdin)) > 0) {
        if (line[c-1] == '\n') line[c - 1] = '\0';
        int n = searchFootpath(footpath, line, output);
        if (n != 0) printf("%s --> %d\n", line, n);
        else printf("%s --> NOTFOUND\n", line);
        fflush(stdout);
    }
    free(line);
}
// returns the grade1lin attribue of a node / footpath struct
double footpathGetGradelin(node_t *f) {
    return f->data->gradelin;
}

// Frees memory stored in the linked list

void freeFootpath(list_t *list) {
    assert(list != NULL);
    node_t *current = list->head;
    while (current) {
        node_t *tmp = current;
        current = current->next;
        footpathFree(tmp->data);
        free(tmp);
    }
    free(list);
}



