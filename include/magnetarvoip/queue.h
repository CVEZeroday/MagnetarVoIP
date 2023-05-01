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
#include <string>
using namespace std;
extern "C" {
#endif

#include <stdlib.h>

typedef union DATA
{
  int t_int;
//  float t_float;

#ifdef __cplusplus
  string t_string;
  DATA() { t_string = ""; }
  ~DATA() {}
#endif
} DATA;

typedef struct Node
{
  DATA data;
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

inline int isEmptyQueue(Queue *q)
{
  return q->count == 0;
}

#define ENQUEUE_FUNC(type)                          \
void enqueue_##type(Queue *q, type data_)           \
{                                                   \
  Node *node = (Node*)malloc(sizeof(Node));         \
  node->data.t_##type = data_;                                \
  node->next = NULL;                                \
  if (isEmptyQueue(q))                              \
  {                                                 \
    q->front = node;                                \
  }                                                 \
  else                                              \
  {                                                 \
    q->rear->next = node;                           \
  }                                                 \
  q->rear = node;                                   \
  q->count++;                                       \
}                                                   

ENQUEUE_FUNC(int);
//ENQUEUE_FUNC(float);
#ifdef __cplusplus
ENQUEUE_FUNC(string);
#endif

#define enqueue(queue, data, type) enqueue_##type(queue, data)

#define DEQUEUE_FUNC(type)                          \
type dequeue_##type(Queue *q)                              \
{                                                   \
  Node* ptr;                                        \
  type data_;                                       \
  ptr = q->front;                                   \
  q->front = ptr->next;                             \
  data_ = ptr->data.t_##type;                       \
  free(ptr);                                        \
  q->count--;                                       \
  return data_;                                     \
}

DEQUEUE_FUNC(int);
//DEQUEUE_FUNC(float);
#ifdef __cplusplus
DEQUEUE_FUNC(string);
#endif

#define dequeue(queue, type) dequeue_##type(queue)


/********************************************/
#ifdef __cplusplus
}
#endif

#endif
