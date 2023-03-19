#ifndef _LIST_H_
#define _LIST_H_

#include "data.h"

// Linked List Data Strcuture Inspired by Workshop 4.6 and listops.c from PPSAA

typedef struct node node_t;

struct node {
	footpath_t *data;
	node_t *next;
};

typedef struct list {
	node_t *head;
	node_t *tail;
	// size_t n;
} list_t;

list_t *make_empty_list();

list_t *appendFoothpath(list_t *list, footpath_t *value);

int buildFootpathList(FILE *f, list_t *footpathList);

void searchDictList(list_t *footpath, FILE *output);

int searchFootpath(list_t *footpath, char *query, FILE *output);

double footpathGetGradelin(node_t *f);

void freeFootpath(list_t *list);


#endif

