#ifndef ARRAY
#define ARRAY

#include <stdlib.h>

#define DEFAULT_ARRAY_SIZE 20

typedef struct Array {
    int *array;

    int used;
    int size;

    void (*insert)(struct Array *, int);
    void (*delete)(struct Array *, int);
    void (*deleteAll)(struct Array *);
} Array;

Array initArray(int init_size);
static void insert(Array *self, int data);
static void delete(Array *self, int index);
static void deleteAll(Array *self);

#endif
