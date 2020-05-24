#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main() {
    Queue_T que;
    que = Queue_init();
    Queue_push(que, (int *) 1);
    Queue_push(que, (int *) 2);
    Queue_push(que, (int *) 3);
    Queue_push(que, (int *) 4);
    printf("Size: %d\n", Queue_size(que));
    Queue_print(que);
    Queue_pop(que);
    printf("Queue after popping: \n");
    Queue_print(que);
    Queue_pop(que);
    printf("Queue after popping: \n");
    Queue_print(que);
    return 0;
}
