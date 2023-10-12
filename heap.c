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

void *heap_top(Heap *pq) {
  if (pq->size == 0) {
    return NULL;
  } else {
    return pq->heapArray[0].data;
  }
}

void heap_push(Heap *pq, void *data, int priority) {
  heapElem *newElem = (heapElem *)malloc(sizeof(heapElem));
  newElem->data = data;
  newElem->priority = priority;

  if (pq->size == 0){
    pq->heapArray[0] = *newElem;
  }
  else if (pq->size == pq->capac){
    pq->heapArray = realloc(pq->heapArray, pq->capac*2+1);
    heap_push(pq,data,priority);
  }
  else{
    pq->heapArray[pq->size] = *newElem;
    
  }
  pq->size++;
}

void heap_pop(Heap *pq) {}

Heap *createHeap() {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->size = 0;
  heap->capac = 3;
  heap->heapArray = (heapElem *)malloc(3 * sizeof(heapElem));
  return heap;
}
