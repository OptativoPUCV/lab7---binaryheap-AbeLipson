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

  if (pq->size == pq->capac) {
    pq->capac = pq->capac * 2 + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
  }

  pq->heapArray[pq->size] = *newElem;

  int currIndex = pq->size;
  while (currIndex > 0) {
    int parentIndex = (currIndex - 1) / 2;

    if (pq->heapArray[currIndex].priority >
        pq->heapArray[parentIndex].priority) {
      heapElem aux = pq->heapArray[currIndex];
      pq->heapArray[currIndex] = pq->heapArray[parentIndex];
      pq->heapArray[parentIndex] = aux;

    } else {
      break;
    }
    currIndex = parentIndex;
  }

  pq->size++;
}

void heap_pop(Heap *pq) {
  pq->heapArray[0] = pq->heapArray[pq->size - 1];

  pq->size--;

  int currIndex = 0;
  while (1) {
    int leftChild = (currIndex * 2) + 1;
    int rightChild = (currIndex * 2) + 2;
    int largest = currIndex;

    if (leftChild < pq->size &&
        pq->heapArray[leftChild].priority > pq->heapArray[largest].priority) {
      largest = leftChild;
    }
    if (rightChild < pq->size &&
        pq->heapArray[rightChild].priority > pq->heapArray[largest].priority) {
      largest = rightChild;
    }

    if(largest !=currIndex){
      heapElem aux = pq->heapArray[currIndex];
      pq->heapArray[currIndex] = pq->heapArray[largest];
      pq->heapArray[largest] = aux;
      currIndex = largest;
    }
    else{
      break;
    }
  }
}

Heap *createHeap() {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->size = 0;
  heap->capac = 3;
  heap->heapArray = (heapElem *)malloc(3 * sizeof(heapElem));
  return heap;
}
