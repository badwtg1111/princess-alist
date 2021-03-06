// -1156203886

#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0

typedef BiTree SElemType;
typedef struct
{
  SElemType* base;
  SElemType* top;
  int stacksize;
}SqStack;

Status InitStack(SqStack* S)
{
  S->base = (SElemType*) malloc(sizeof(SElemType) * STACK_INIT_SIZE);
  if (!S->base) exit(OVERFLOW);
  S->top = S->base;
  S->stacksize = STACK_INIT_SIZE;
  return OK;
}

SElemType GetTop(SqStack S)
{
  if (S.base == S.top)
    return ERROR;
  return *(S.top - 1);
}

Status Push(SqStack* S, SElemType e)
{
  if (S->top - S->base >= S->stacksize)
  {
    S->base = (SElemType*) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
    if (!S->base) exit(OVERFLOW);
    S->top = S->base + S->stacksize;
    S->stacksize += STACKINCREMENT;
  }

  *S->top++ = e;
  return OK;
}

Status Pop(SqStack* S, SElemType* e)
{
  if (S->base == S->top)
    return ERROR;
  *e = *--S->top;
  return OK;
}

// Status PrintStack_Sq(SqStack S)
// {
//   if (S.base == S.top)
//     return ERROR;
// 
//   while (S.base++ != S.top)
//     printf("%.2f ", *S.base);
//   printf("\n");
//   return OK;
// }

Status StackEmpty(SqStack S)
{
  if (S.base == S.top)
    return TRUE;
  return FALSE;
}

#endif
