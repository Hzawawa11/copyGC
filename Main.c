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

Object* R[RN];

int main(void){

  init_Semispaces();
  Heaptable();

  R[0] = ListMake(3);
  ListDisp(R[0]);
  R[1] = ListMake(5);
  ListDisp(R[1]);
  
  R[1] = ListDelete(2, R[1]);
  ListDisp(R[1]);
  R[0] = ListMake(3);

  ListDisp(R[0]);
  ListDisp(R[1]);

  // pop_local();
  // pop_local();
  /*
  free(freelistINT);
  free(freelistPAIR);
  */
}