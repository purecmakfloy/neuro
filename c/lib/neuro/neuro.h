// neuro.h
#ifndef NEURO_H
#define NEURO_H

// https://github.com/troglobit/libicmp

typedef struct node {
    int val;                // temporary var
    int ping_ms;
    int bandwidth;
    unsigned char mac_addr[6];

    struct node* next ;
} node_t;

void print_list(node_t * head);
void push_behind(node_t * head, int val);
void push_before(node_t ** head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);

#endif
