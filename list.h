/*
* Programer : Hanzawa JUNICHI
* Date : July 25th (Wed), 2016 
*/
#ifndef LIST_H
#define LIST_H
/* Function Prototype */
  Object* ListMake(int n);
  void ListDisp(Object* list);
  Object* ListDelete(int n, Object* obj);
  Object* ListInsert(int n, Object* list, Object* obj);
#endif