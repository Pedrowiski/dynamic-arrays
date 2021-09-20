#include "array.h"

Array initArray(int init_size) {
    Array self;

    if (init_size == 0) {
        init_size = DEFAULT_ARRAY_SIZE;
    }

    self.array = calloc(init_size, sizeof(int));
    self.used  = 0;
    self.size  = init_size;

    self.insert    = insert;
    self.delete    = delete;
    self.deleteAll = deleteAll;

    return self;
}

static void insert(Array *self, int data) {
    if (self->used == self->size) {
        self->size *= 2;
        self->array =  realloc(self->array, self->size * sizeof(int));
    }

    self->array[self->used++] = data;
}

static void delete(Array *self, int index) {
    int real_position = self->used - 1;
    int distance      = real_position - index;

    if ((index > real_position) || (index < 0)) {
        return;
    } else {
        for (int counter = 0; counter < distance; counter++) {
            self->array[index + counter] = self->array[index + counter + 1];
        }

        self->array[real_position] = 0;
        self->used--;
    }

    if ((self->used * 2) <= (self->size / 2)) {
        self->array = realloc(self->array, self->used * sizeof(int));
        self->size  /= 2;
    }
}

static void deleteAll(Array *self) {
    free(self->array);
    self->size = 0;
    self->used = 0;

    self->insert    = NULL;
    self->delete    = NULL;
    self->deleteAll = NULL;
}
