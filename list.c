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
  for(i = 1; i <= n; i++)
    lead = cons(NULL, lead);
  return lead;
}

void ListDispN(int n, Object* list){
  if(n < 0){
    printf("Error 3\n");
    exit(1);
  }
  int i;
  Object* tmp = list;
  for(i = 1; i <= n; i++){
    // printf("%d\n", i);
    if(i == n){
      ;
      // printf("(%p . %p)\n", car(tmp), cdr(tmp));
    }
    tmp = cdr(list);
  }
}
// #define isNEXT() 
void disp(Object* list){
  /* car phase */
  if(car(list) == NULL){
    printf("'()");
  }else if(_TYPE(car(list)) == T_INT){
    printf("%d", _DINT(car(list)) );
    // printf("%d", _DINT(list) );

  }
  else if(_TYPE(car(list)) == T_PTR){
    ListDisp(list);
  }

  /*cdr phase*/
  if(cdr(list) == NULL){
    printf(" . ");
    printf("'()");
  }else if(_TYPE(cdr(list)) == T_INT){
    printf(" . ");
    printf("%d", _DINT(list) );
  }
  else if(_TYPE(cdr(list)) == T_PTR){
    printf(" ");
    disp(cdr(list));    
  }
}

void ListDisp(Object* list){
  if(car(list) == NULL && cdr(list) == NULL ){
    puts("'()");
    goto end;
  }
  printf("(");
  disp(list);
  printf(")\n");
  end: ; 
}

Object* ListUpdate(int n, Object* list, int e){
  if(ListError(n)){
    printf("Error 5\n");
    exit(1);
  }
  if(n == 1){
    car(list) = atom(e);
  }else{
    ListUpdate(--n, cdr(list), e);
  }
  return list;
}


Object* ListDelete(int n, Object* obj){
  if(ListError(n)){
    printf("Error 4\n");
    exit(1);
  }
  if(n == 1){
    if(cdr(cdr(obj)) == NULL) 
      cdr(obj) = NULL;
    else 
      cdr(obj) = cdr(cdr(obj));
  }else{
    if(cdr(cdr(obj)) == NULL) 
      return obj;
    ListDelete(--n, cdr(obj));
  }
  return obj;
}
void ListUpdateN(Object* list, int e){
  car(list) = atom(e);
  if(cdr(list) != NULL){
    ListUpdateN(cdr(list), ++e);
  }
}

// Object* ListInsert(int n, Object* list, Object* obj){
  
//   if(ListError(n))
//     return NULL;

//   if(n == 1){
//     cdr(obj) = cdr(list);
//     cdr(list) = obj;
//   }
//   else{ 
//     ListInsert(--n, list, obj);
//   }
//   return list;
  
// }



Object* ListInsert(int n, Object* list){
  
  if(ListError(n))
    return NULL;

  if(n == 1){
    Object* obj = cons(NULL, NULL);
    cdr(obj) = cdr(list);
    cdr(list) = obj;
  }
  else{ 
    ListInsert(--n, list);
  }
  return list;
  
}