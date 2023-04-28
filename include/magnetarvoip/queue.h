#ifndef __QUEUE_H__
#define __QUEUE_H__
/********************************************/
/* This source code is part of MagnetarVoIP */
/********************************************/
/*     Copyrights (C) 2023 CVE_zeroday.     */
/*          All rights reserved.            */
/********************************************/
/*           File Name: queue.h             */
/*   Created by CVE_zeroday on 12.03.2023   */
/*               (T.Y.Kim)                  */
/********************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************/

#include <stdlib.h>

typedef struct Node
{
  void* data;
  struct Node* next;
} Node;

typedef struct Queue
{
  Node* front;
  Node* rear;
  int count;
} Queue;

inline void initQueue(Queue *q)
{
  q->front = NULL;
  q->rear = NULL;
  q->count = 0;
}

inline bool isEmptyQueue(Queue *q)
{
  return q->count == 0;
}

inline void enqueue(Queue *q, void *data)
{
  Node *node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (isEmptyQueue(q))
  {
    q->front = node;
  }
  else
  {
    q->rear->next = node;
  }
  q->rear = node;
  q->count++;
}

// returns -1 when Queue is empty
// returns 0 when dequeued normally
inline int dequeue(Queue *q)
{
  void* data;
  Node* ptr;
  if (isEmptyQueue(q))
  {
    return -1;
  }
  ptr = q->front;
  data = ptr->data;
  q->front = ptr->next;
  free(ptr);
  q->count--;

  return 0;
}

/********************************************/
#ifdef __cplusplus
}
#endif

#endif
