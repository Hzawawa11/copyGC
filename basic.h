#ifndef BASIC_H
#define BASIC_H

#define TRUE 1
#define FALSE 0

#define car(o) (o->Pair.car)
#define cdr(o) (o->Pair.cdr)
#define rplaca(o, data) (car(o) = data)
#define rplacd(o, data) (cdr(o) = data)


/* basic.c */
Object* cons(Object* car, Object* cdr);
Object* atom(int i);

/*gc.c*/
void gc(void);
void flip(void); //copyGC
void scan(Object* obj);
Object* forward(Object* fromRef);
Object* copy(Object* fromRef);
void move(Object* fromRef, Object* toRef);
void RootScan(void);

void init_gcs(void);
int push_gcs(Object* obj);
Object* pop_gcs(void);
void init_local(void);
int push_local(Object* obj);
Object* pop_local(void);

void init_Semispaces(void);
Object* allocate(u_int64_t size);

/*state.c*/
void state_Obj(char* str, Object* obj);
void Heaptable(void);

#endif
