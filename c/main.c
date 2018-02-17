//#include "neuro.h"
#include "neuro.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    node_t * head = NULL;
    head = malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    head->channel.master.ping_ms = 3;
    head->next = NULL;
    print_list(head);
    return 0;
}

