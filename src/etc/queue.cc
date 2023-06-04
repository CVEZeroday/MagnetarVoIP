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

#include "queue.h"

void enqueue_int(Queue* q, int data_)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data.t_int = data_;
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

/*
void enqueue_float(Queue* q, float data_)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data.t_float = data_;
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
*/

void enqueue_string(Queue* q, std::string data_)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data.t_string = data_;
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

int dequeue_int(Queue* q)
{
  Node* ptr;
  int data_;
  ptr = q->front;
  q->front = ptr->next;
  data_ = ptr->data.t_int;
  free(ptr);
  q->count--;
  return data_;
}

/*
float dequeue_float(Queue* q)
{
  Node* ptr;
  float data_;
  ptr = q->front;
  q->front = ptr->next;
  data_ = ptr->data.t_float;
  free(ptr);
  q->count--;
  return data_;
}
*/

std::string dequeue_string(Queue* q)
{
  Node* ptr;
  std::string data_;
  ptr = q->front;
  q->front = ptr->next;
  data_ = ptr->data.t_string;
  free(ptr);
  q->count--;
  return data_;
}