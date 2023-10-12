#include "heap.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  void *data;
  int priority;
} heapElem;

typedef struct Heap {
  heapElem *heapArray;
  int size;
  int capac;
} Heap;

void *heap_top(Heap *pq) { return pq->heapArray[0].data; }

void heap_push(Heap *pq, void *data, int priority) {}

void heap_pop(Heap *pq) {}

Heap *createHeap() {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->size = 0;
  heap->capac = 3;
  heap->heapArray = (heapElem *)malloc(3 * sizeof(heapElem));
  return heap;
}
