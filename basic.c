#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"

#define EMPTY_LIST(list) (list == NULL)

Object* allocate(u_int64_t size){
  Object* result = freeptr;
  Object* newfree = (u_int64_t)freeptr+(size);
  if (newfree > top){
    gc();
    result = freeptr;
    newfree = (u_int64_t)freeptr+(size);
    if (newfree > top){
      printf("Error: 2\n");
      exit(0);
    }
  }    
  freeptr = newfree;
  // printf("allocate: %p\n", result);
  // printf("nextallocate: %p\n", freeptr);
  return result;
}

Object* cons(Object* car, Object* cdr){
  push_local(cdr);

  Object* obj = allocate(PAIRSIZE);  
  _TYPE(obj) = T_PTR;
  _FORWADING(obj) = 0x00;
  car(obj) = car;
  cdr = pop_local();
  cdr(obj) = cdr;
  return obj;
}

Object* atom(int i){
  Object* obj = allocate(DINTSIZE);
  _FORWADING(obj) = 0x00;
  _TYPE(obj) = T_INT;
  _DINT(obj) = i;
  return obj;
}
