#ifndef ARRAY_OPERATIONS
#define ARRAY_OPERATIONS 1

#define RANDOM           0
#define ASCENDING        1
#define DESCENDING       2
#define ALMOST_ORDERED   3

void random_dataset(int *data, int size);

void ascending_dataset(int *data, int size);

void descending_dataset(int *data, int size);

void almost_ordered_dataset(int *data, int size);

int* generate_array(int size, int organization);

#endif
