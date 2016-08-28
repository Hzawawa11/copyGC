#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"

Object* top;
Object* toSpace;
Object* fromSpace;
Object* freeptr;


void state_Obj(char* str, Object* obj)
{
  if(obj == NULL){
    printf("%p\n", NULL);
    goto end;
  }

  printf("%s pointer: %p\n", str, obj);
  
  if (_TYPE(obj) == T_PTR){
    printf("%10s%s","> T_PTR:", "(");
    switch(_TYPE(car(obj))){
    case T_INT:
      printf("%d", _DINT(car(obj)));
      break;
    case T_PTR:
      printf("%p", car(obj));
      break;
    default:
      break;
    }
    printf(".");
    switch(_TYPE(cdr(obj))){
    case T_INT:
      printf("%d",_DINT(cdr(obj)));
      break;
    case T_PTR:
      printf("%p", cdr(obj));
      break;
    default:
      break;
    }
    printf(")\n");
  }else if (_TYPE(obj) == T_INT){
    printf("%10s(%d)\n", "> T_INT: ", _DINT(obj));
  }
  end: ;
}

void Heaptable(void){
  int i = 1;
  // printf("freeptr %p\n", freeptr);
  // printf("top     %p\n", top);
  Object* tmp_to = (u_int64_t)toSpace;  
  Object* tmp_from = (u_int64_t)fromSpace;  
  printf("    %18s |%18s\n", "toSpace", "fromSpace");
  while (tmp_to < top){
    printf("%3d %18p |%18p\n", i, tmp_to, tmp_from);
    tmp_to = (u_int64_t)tmp_to+(PAIRSIZE) ;
    tmp_from = (u_int64_t)tmp_from+(PAIRSIZE); 
    i++;
  }
}