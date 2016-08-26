#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"

Object* toSpace;
Object* fromSpace;
Object* Heap;
Object* top;
Object* freeptr;
Object* R[RN];

Object* gcs[STACKSIZE];
int sp;
Object* local[STACKSIZE];
int local_sp;

#define STR(str) (#str)
#define isEMPTY() (sp == 0)

void init_Semispaces(void){
  // Heap = (Object*)malloc(2*EXTENT * PAIRSIZE * sizeof(char));
  Heap = (Object*)malloc(PAIRSIZE);
  toSpace = Heap;
  fromSpace = (u_int64_t)toSpace+(EXTENT*PAIRSIZE);
  top = fromSpace;
  freeptr = toSpace; 
  state_Obj(STR(toSpace), toSpace);
  state_Obj(STR(fromSpace), fromSpace);
}

Object* allocate(void){
  Object* result = freeptr;
  Object* newfree = (u_int64_t)freeptr+(PAIRSIZE);
  if (newfree > top){
    printf("\n StartCopy GC\n");
    gc();
    result = freeptr;
    newfree = (u_int64_t)freeptr+(PAIRSIZE);
    if (newfree > top){
      printf("Error: 2\n");
      exit(0);
    }
  }    
  freeptr = newfree;
  printf("allocate: %p\n", result);
  return result;
}

void flip(void){
  Object* tmp = toSpace; 
  toSpace = fromSpace; 
  fromSpace = tmp; 
  top = (u_int64_t)toSpace+(EXTENT*PAIRSIZE);
  freeptr = toSpace;
}


void gc(void){
  // init_toSpace();
  flip();
  init_gcs();
  RootScan();
  while( !isEMPTY() ){
    Object* p = pop_gcs();
    // printf("!! %p\n", p);
    scan(p);
  }
}


void RootScan(void){
  int i;
  for(i = 0; i < RN; i++){
    if (R[i] != NULL) {
      R[i] = forward(R[i]);
    }
  }
  
  for(i = 0; i < STACKSIZE; i++){
    if (local[i] != NULL){
      // printf("!! %p\n", local[i]);
      local[i] = forward(local[i]);
      // push_gcs(local[i]); 
    }
  }
  
}

void scan(Object* obj){
  if(_TYPE(obj) != T_PTR){
    goto end;
  }
  if(car(obj) != NULL){
    car(obj) = forward(car(obj));
  }
  if(cdr(obj) != NULL){
    cdr(obj) = forward(cdr(obj));
  }
  end:;
}


Object* forward(Object* fromRef){
  Object* toRef = _FORWADING(fromRef);
  // printf("end %p -> %p\n", fromRef, toRef);
  if (toRef == NULL){
    // printf("end %p -> %p\n", fromRef, toRef);
    toRef = copy(fromRef);
  }
  return toRef;
}

Object* copy(Object* fromRef){
  Object* toRef = freeptr;
  freeptr = (u_int64_t)freeptr+(PAIRSIZE);
  move(fromRef, toRef);
  printf("%p  -->  %p\n", fromRef, toRef);
  _FORWADING(fromRef) = toRef;
  push_gcs(toRef);
  return toRef;
}

void move(Object* fromRef, Object* toRef){
  car(toRef) = car(fromRef);
  cdr(toRef) = cdr(fromRef);
  _TYPE(toRef) = _TYPE(fromRef);
  _FORWADING(toRef) = 0x00;
}


void init_local(void){
  int i;
  for(i = 0; i < STACKSIZE; i++)
    local[i] = NULL;
}

int push_local(Object* obj){
  if (local_sp < STACKSIZE){
    // _MARK(obj) = TRUE;
    local[local_sp] = obj;
    local_sp++;
    return TRUE;
  } else { /* Error */
    return FALSE;
  }
}

Object* pop_local(void){
  if (local_sp > 0) {
    local_sp--;
    return local[local_sp];
  } else {
    return FALSE;
  }
}

void init_gcs(void){
  int i;
  for(i = 0; i < STACKSIZE; i++)
    gcs[i] = NULL;
}

int push_gcs(Object* obj){
  if (sp < STACKSIZE){
    gcs[sp] = obj;
    sp++;
    return TRUE;
  } else { /* Error */
    return FALSE;
  }
}

Object* pop_gcs(){
  if (sp > 0) {
    sp--;
    return gcs[sp];
  } else {
    return FALSE;
  }
}
