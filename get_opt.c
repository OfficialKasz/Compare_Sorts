#include "get_opt.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static const char *optString = "a:n:s:P";

int check_opt(int argc){
    return argc > 6;
}

int get_sort_method(char method[]) {
    int selected_method;
    //printf("%d\n", selected_method);
    if(strcmp(method, "selection") == 0)
        selected_method = SELECTION;
    else if(strcmp(method, "insertion") == 0)
        selected_method = INSERTION;
    else if(strcmp(method, "shell") == 0)
        selected_method = SHELL;
    else if(strcmp(method, "quick") == 0)
        selected_method = QUICK;
    else if(strcmp(method, "heap") == 0)
        selected_method = HEAP;
    else if(strcmp(method, "merge") == 0)
        selected_method = MERGE;
    else if(strcmp(method, "gpuquick") == 0)
        selected_method = GPUQUICK;
    else if(strcmp(method, "gpumerge") == 0)
        selected_method = GPUMERGE;
    else
        selected_method = UNDEFINED;
    return selected_method;
}

int get_array_size(char sizeOpt[]) {
    int size = atoi(sizeOpt);
    if(size < 0) 
        size = UNDEFINED;
    return size;
}

void get_opt(int argc, char **argv, int *method, int *size, int *array_type, int *print_vector) {
    int opt = 0;
    opt = getopt(argc, argv, optString);
    //a:n:s:p
    while(opt != -1) {
        switch(opt) {
            case 'a': // algorithm
                *method = get_sort_method(optarg);
                break;

            case 'n': // number of elements
                *size   = get_array_size(optarg);
                break;

            case 's': // (vector) situation
                *array_type   = get_array_type(optarg);
                break;

            case 'P': // print
                *print_vector = 1;
            break;

            default:
                /* You won't actually get here. */
                break;
        }

        opt = getopt(argc, argv, optString);
    }
}

char* get_method_name(int method){
    char *name;
    switch(method){
        case SELECTION:
            name = "Selection";
            break;
        case INSERTION:
            name = "Insertion";
            break;
        case SHELL:
            name = "Shell";
            break;
        case QUICK:
            name = "Quick";
            break;
        case HEAP:
            name = "Heap";
            break;
        case MERGE:
            name = "Merge";
            break;
        case GPUQUICK:
            name = "CUDA Quick Sort";
            break;
        case GPUMERGE:
            name = "CUDA Merge Sort";
            break;
        case UNDEFINED:
        default:
            name = " - ";
            break;
    }
    return name;
}

char* get_array_type_name(int type){
    char *name;
    switch(type){
        case RANDOM:
            name = "Random";
            break;
        case ASCENDING:
            name = "Ascending Order";
            break;
        case DESCENDING:
            name = "Descending Order";
            break;
        case ALMOST_ORDERED:
           name = "Almost Sorted";
            break;
        case UNDEFINED:
        default:
            name = " - ";
            break;
    }
    return name;
}
