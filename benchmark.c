#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "basic.h"
#include "list.h"

Object* R[RN];
int Length[RN];

double _UserSec(){
  struct rusage t;
  struct timeval tv;
  getrusage(RUSAGE_SELF, &t);
  tv = t.ru_utime;
  return tv.tv_sec + (double)tv.tv_usec*1e-6;
}

double _SystemSec(){
  struct rusage t;
  struct timeval tv;
  getrusage(RUSAGE_SELF, &t);
  tv = t.ru_stime;
  return tv.tv_sec + (double)tv.tv_usec*1e-6;
}

void benchmark(void){
  double UserBeginSec, UserEndSec;
  double SysBeginSec, SysEndSec;
  int i;
  int tmp;
  
  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 0; i < RN; i++){
    R[i] = ListMake(LISTSIZE);
    ListUpdateN(R[i], 1);
    Length[i] = LISTSIZE;
  }
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n", SysEndSec - SysBeginSec);
  
  
  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 0; i < LISTSIZE/10; i++)
    ListDispN(rand()%LISTSIZE, R[rand()%RN]);  //R[n][m]をランダムアクセス
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n", SysEndSec - SysBeginSec);
  
  
  for(i = 0; i < LISTSIZE/10; i++){
    tmp = rand()%RN;
    R[tmp] = ListDelete(rand()%Length[tmp]+1, R[tmp]);
    Length[tmp] -= 1;
  }

  for(i = 0; i < LISTSIZE/10; i++){
    tmp = rand()%RN;
    R[tmp] = ListInsert(rand()%Length[tmp]+1, R[tmp]);
    Length[tmp] += 1;
  }

  
  // gc();
  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 0; i < LISTSIZE/10; i++){
    tmp = rand()%RN;
    ListDispN(rand()%Length[tmp]+1, R[tmp]);
  }
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n", SysEndSec - SysBeginSec);
  
}

void benchmark2(void){
  double UserBeginSec, UserEndSec;
  double SysBeginSec, SysEndSec;
  int i;
  int tmp;
  

  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  R[0] = ListMake(LISTSIZE);
  ListUpdateN(R[0], 1);
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n",  SysEndSec - SysBeginSec);

  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 0; i < LISTSIZE/10; i++)
    ListDispN(rand()%LISTSIZE+1, R[0]);
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n",  SysEndSec - SysBeginSec);

  /* random sort */  
  SysBeginSec = _SystemSec();
  UserBeginSec = _UserSec();
  for(i = 0; i < (LISTSIZE/10); i++)
    R[0] = ListDelete(rand()%(LISTSIZE-i), R[0]);
  for(i = 0; i < (LISTSIZE/10); i++)
    R[0] = ListInsert(rand()%(LISTSIZE-(LISTSIZE/10)+i), R[0]);
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n", SysEndSec - SysBeginSec);
  
  // gc();
  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 0; i < LISTSIZE/10; i++)
    ListDispN(rand()%LISTSIZE+1, R[0]);
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User: %10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n", SysEndSec - SysBeginSec);
} 

void benchmark3(void){
  double UserBeginSec, UserEndSec;
  double SysBeginSec, SysEndSec;
  int i;

  UserBeginSec = _UserSec();
  SysBeginSec = _SystemSec();
  for(i = 1; i <= 100; i++){
    R[0] = ListMake(LISTSIZE);
  }
  UserEndSec = _UserSec();
  SysEndSec = _SystemSec();
  printf("  User:%10.10f[sec]\n", UserEndSec - UserBeginSec);
  printf("System:%10.10f[sec]\n",  SysEndSec - SysBeginSec);
}

