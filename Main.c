/* 
* Programer: Hanzawa JUNCHI
* Date: 2016, Augast 25 --
* Abstruct: CopyGC (Stop the world)
*/

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"
#include "list.h"
#define COPY

Object* R[RN];

int main(void){

  init_Semispaces();
  // Heaptable();
  // printf("PairSize: %ld\n", PAIRSIZE);
  // printf("DintSize: %ld\n", DINTSIZE);

  benchmark();
  puts("\n\n");
  benchmark2();
  puts("\n\n");
  benchmark3();
  /*
  Object* int_20 = atom(20);
  Object* int_50 = atom(50);
  Object* int_10 = atom(20);
*/
  // push_local(int_20);
  // push_local(int_50);
  // push_local(int_10);

  
  // R[0] = ListMake(10);
  // printf("%p\n", R[0]);
  // R[0] = ListUpdate(5, R[0], 10); //4
  // ListUpdateN(R[0], 1);
  // printf("%p\n", R[0]);
  // printf("(%p . %p)\n", car(R[0]), cdr(R[0]));
  // ListDispN(5, R[0]);
  // ListDisp(R[0]);
/*
  R[1] = ListMake(5);  //5
  ListDisp(R[1]);

  R[0] = ListInsert(3, R[1]);
  ListDisp(R[1]);
  
  R[1] = ListDelete(2, R[1]); //2 
  ListDisp(R[1]);
  */
  // ListDisp(R[0]);
  // ListDisp(R[1]);
  
}