#include <stdio.h>
#include <string.h>

#include "array.h"

int main(void) {
    Array vector = initArray(10);

    for (int count = 0; count < 1000; count++) {
        vector.insert(&vector, count);
    }

    /*for (int count = 0; count < 999; count++) {
        vector.delete(&vector, 0);
    }*/

    for (int count = 0; count < vector.size; count++) {
        printf("%d\n", vector.array[count]);
    }

    printf("\n%d %d\n", vector.size, vector.used);

    return 0;
}
