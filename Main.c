/* 
* Programer: Hanzawa JUNCHI
* Date: 2016, Augast 22 --
* Abstruct: MarkSweepGC (Stop the world)
*/
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"
#include "list.h"

Object* R[RN];
/* test */
Object* toSpace;
Object* fromSpace;
/* prototype function */

int main(void){

  init_Semispaces();
  Heaptable();

  // Object* int_50 = atom(50);
  // Object* int_20 = atom(20);
  // R[0] = cons(int_50, int_20);
  // state_Obj("R[0]", R[0]);
  // R[0] = int_20;
  R[0] = ListMake(3);
  ListDisp(R[0]);
  R[1] = ListMake(3);
  ListDisp(R[1]);
  R[0] = ListMake(4);
  ListDisp(R[0]);

  R[2] = ListMake(3);
  ListDisp(R[2]);
  R[2] = ListDelete(2, R[2]);
  ListDisp(R[2]);
  R[3] = ListMake(1);
  ListDisp(R[3]);
  R[4] = ListMake(1);
  ListDisp(R[4]);


  /*
  state_Obj("allocate", allocate());
  flip();
  */
  // state_list();
  /*Int Data*/
  /*
  Object* int_50 = atom(50);
  Object* int_20 = atom(20);
  init_local();
  push_local(int_20);
  push_local(int_50);
  */
  /*
  R[0] = ListMake(3);
  ListDisp(R[0]);
  R[0] = ListMake(5);
  ListDisp(R[0]);
  R[0] = ListDelete(2, R[0]);
  ListDisp(R[0]);
  R[0] = ListMake(3);
  ListDisp(R[0]);
  // R[0] = ListDelete(, R[0]);
  // ListDisp(R[0]);

  R[1] = cons(NULL, NULL);
  R[0] = ListInsert(1, R[0], R[1]);
  ListDisp(R[0]);
  */
  // pop_local();
  // pop_local();
  /*
  free(freelistINT);
  free(freelistPAIR);
  */
}