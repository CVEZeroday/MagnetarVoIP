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
#include "nw.hpp"
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
void enqueue_int(Queue* q, int data_);
//void enqueue_float(Queue* q, float data_);
//#define enqueue(queue, data, type) enqueue_##type(queue, data)

int dequeue_int(Queue *q);
//float dequeue_float(Queue* q);
//#define dequeue(queue, type) dequeue_##type(queue)


/********************************************/
#ifdef __cplusplus
}

void enqueue_string(Queue* q, std::string data_);
std::string dequeue_string(Queue* q);
void enqueue_NW_PACKET(Queue* q, NW_PACKET data_);
NW_PACKET dequeue_NW_PACKET(Queue* q);

#endif

#endif
