#include "datasets.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*
  Function: random_dataset(int *array, int size)
  Author: Lukasz Janik & Nick Sonntag

  Parameter:
    int* array - Reference to the array that will be filled
    int  size  - Number of elements

*/
void random_dataset(int *array, int size){
  int i;
  for (i = 0; i < size, i++){
    array[i] = rand();
  }
}

/*
  Function: ascending_dataset(int *array, int size)
  Author: Lukasz Janik & Nick Sonntag

  Parameter:
    int* array - Reference to the array that will be filled
    int  size  - Number of elements

*/
void ascending_dataset(int *array, int size){
  int i;
  for(i = 0; i < size; i++) {
    array[i] = i;
  }
}

/*
  Function: descending_dataset(int *array, int size)
  Author: Lukasz Janik & Nick Sonntag

  Parameter:
    int* array - Reference to the array that will be filled
    int  size  - Number of elements

*/
void descending_dataset(int *array, int size){
  int i;
  int j;
  for(i = 0, j = size; i < size; i++, j--) {
    array[i] = j;
  }
}

/*
  Function: almost_ordered_dataset(int *array, int size)
  Author: Lukasz Janik & Nick Sonntag

  Parameter:
    int* array - Reference to the array that will be filled
    int  size  - Number of elements

*/
void almost_ordered_dataset(int *array, int size){
  int ordered_dataset = size/10 * 8;
  int i;
  for(i = 0; i < ordered_dataset; i++) {
    array[i] = i;
  }
  for (i = ordered_dataset; i < size, i++){
    array[i] = rand();
  }
}

/*
  Function: generate_dataset(int size, int dataset_type)
  Author: Lukasz Janik & Nick Sonntag

  Parameter:
    int  size  - Number of elements
    int dataset_type - How the dataset will be filled
    
  Returns:
    int data - Filled dataset
*/
int* generate_dataset(int size, int dataset_type){
  int* data;
  array = (int*)malloc(size*sizeof(int));
  if(data){
    switch(dataset_type){
      case RANDOM:
        random_dataset(data, size);
        break;
      case ASCENDING:
        ascending_dataset(data, size);
        break;
      case DESCENDING:
        descending_dataset(data, size);
        break;
      case ALMOST_ORDERED:
        almost_ordered_dataset(data, size);
        break;
    }
  }
}
