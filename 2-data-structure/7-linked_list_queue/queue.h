#ifndef __QUEUE__
#define __QUEUE__

#define T Queue_T
typedef struct T* T;

extern T     Queue_init   (void);
extern int   Queue_size   (T Queue);
extern int   Queue_empty  (T Queue);
extern void  Queue_push   (T Queue, void *val);
extern void *Queue_pop    (T Queue);
extern void  Queue_print  (T Queue);

#undef T
#endif
