#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"

#define EMPTY_LIST(list) (list == NULL)
#define CHECK(o) \
  if(_TYPE(o) != T_INT && _TYPE(o) != T_PTR){\
    puts("Error: 1");exit(0);\
  }

Object* cons(Object* car, Object* cdr){
  
  // CHECK(car); CHECK(cdr);
  Object* obj = allocate();
  _TYPE(obj) = T_PTR;
  _FORWADING(obj) = 0x00;
  car(obj) = car;
  cdr(obj) = cdr;
  return obj;
}

Object* atom(int i){
  Object* obj = allocate();
  _FORWADING(obj) = 0x00;
  _TYPE(obj) = T_INT;
  _DINT(obj) = i;
  return obj;
}
