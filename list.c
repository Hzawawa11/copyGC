#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "list.h"
#include "basic.h"

#define ListError(n) (n < 1)

Object* ListMake(int n){
  Object* lead = NULL;
  int i = 1;
  if(ListError(n))
    return NULL;
  for(i = 1; i <= n; i++){
    lead = cons(NULL, lead);
    // pop_local();
    // push_local(lead);
  }
  return lead;
}

// #define isNEXT() 
void disp(Object* list){
  /* car phase */
  if(car(list) == NULL){
    printf("'()");
  }else if(_TYPE(car(list)) == T_PTR){
    ListDisp(list);
  }


  /*cdr phase*/
  if(cdr(list) == NULL){
    printf(" . ");
    printf("'()");
  }
  else if(_TYPE(cdr(list)) == T_PTR){
    // printf("%d", cdr(list));
    printf(" ");
    disp(cdr(list));    
  }
}

void ListDisp(Object* list){
  if(_TYPE(list) == NULL){
    goto end;
  }
  printf("(");
  disp(list);
  printf(")\n");

  /*
  if(list == NULL){
    printf("NIL\n");
    goto end;
  }
  if (_TYPE(list) == T_PTR){
    if(cdr(list) != NULL){
      printf("(- . %p)", cdr(list));
      ListDisp(cdr(list));
    }
    else{
      printf("(- . -)\n");
    }
  }*/
  end: ; 
}

Object* ListDelete(int n, Object* obj){
  if(ListError(n))
    return NULL;
  if(n == 1){
    if(cdr(cdr(obj)) == NULL) 
      cdr(obj) = NULL;
    else 
      cdr(obj) = cdr(cdr(obj));
  }else{
    if(cdr(cdr(obj)) == NULL) return obj;
    ListDelete(--n, cdr(obj));
  }
  return obj;
}

Object* ListInsert(int n, Object* list, Object* obj){
  if(ListError(n))
    return NULL;

  if(n == 1){
    cdr(obj) = cdr(list);
    cdr(list) = obj;
  }
  else{ 
    ListInsert(--n, list, obj);
  }
  return list;
}