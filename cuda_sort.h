#define MAX_DEPTH       16
#define INSERTION_SORT  32

// Interface to call CUDA Quick Sort
void gpu_qsort(int *data, int nitems);
// Interface to call CUDA Merge Sort
void gpumerge_sort(int* a,int n);
