#ifndef STRUCTURE_H
#define STRUCTURE_H

#define T_INT 1 
#define T_PTR 2  

#define _TYPE(o) o->Dummy.tt
#define _FORWADING(ref) (ref->Dummy.fowarding)
#define _DINT(o) o->Dint.data.i
#define _DLINK(o) o->Dint.data.link
 
/* Data Structure */
typedef struct mark_O{
  union {
    
    struct{
      char tt;
      struct mark_O* fowarding;
    }Dummy;

    struct{
      char tt;
      struct mark_O* fowarding;
      struct mark_O* car;
      struct mark_O* cdr;
    }Pair;
    
    struct{
      char tt;
      struct mark_O* fowarding;
      union {
        // struct mark_O* link;
        int i;
      }data;
    }Dint;

  };
} Object;



#define PAIRSIZE (sizeof(Object)+sizeof(Object)+sizeof(Object)+sizeof(char))
#define DINTSIZE (sizeof(Object)+sizeof(int)+sizeof(char))

#define LISTSIZE 100000

#define RN 5
#define STACKSIZE 1000000

#define MB 1000000
#define MEM 512
#define HEAPSIZE (sizeof(char)*MEM*MB)
#define EXTENT (sizeof(char)*(MEM/2)*MB)

extern Object* gcs[STACKSIZE];
extern int sp;
extern Object* local[STACKSIZE];
extern int local_sp;

extern Object* R[RN];
extern Object* Heap;
extern Object* top;
extern Object* toSpace;
extern Object* fromSpace;
extern Object* freeptr;

#endif
