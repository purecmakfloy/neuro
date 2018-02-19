//#include "neuro.h"
#include "../lib/neuro/neuro.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->ping_ms = 3;
    head->next = NULL;
    print_list(head);

const int MAX_CLIENTS = 10;
node_t deikstry[MAX_CLIENTS][MAX_CLIENTS];
deikstry[0][1].ping_ms = 4;
printf("%d\n", deikstry[0][1].ping_ms);
    return 0;
}

