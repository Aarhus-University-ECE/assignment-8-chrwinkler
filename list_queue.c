#include "list_queue.h"
#include <stdbool.h>
#include <stdlib.h>

void init_queue(queue *q)
{
  // Add your init_queue
  // to initialize q, we have to give them value for all ends and the size
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

int empty(queue *q)
{
  // Add your empty function
  // uses same teknik as in stack
  if (q->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function
  // we will make a new placeholder to hold ouer new x value.
  // it will be a pointer to qnode

  qnode *enq;
  enq = malloc(sizeof(qnode));
  enq->next = NULL;
  enq->data = x;
  if (empty(q) == 1)
  {
    q->front = enq;
  }
  else
  {
    q->rear->next = enq;
  }
  q->rear = enq;
  q->size += 1;
}

int dequeue(queue *q)
{
  // Add your dequeue functio
  // again thinking it has pop in a stack from the front side.
  int x;
  qnode *deq;

  deq = q->front;
  x = q->front->data;
  q->front = q->front->next;
  free(deq);
  q->size -= 1;

  return (x);
}
