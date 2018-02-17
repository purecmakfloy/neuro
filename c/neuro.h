// neuro.h
#ifndef NEURO_H
#define NEURO_H

static struct variables {
    int ping_ms;
};

static struct channel {
    struct variables master;
    struct variables slave;
};

typedef struct node {
        int val;
        struct channel channel;
        struct node * next;
} node_t;

void print_list(node_t * head);
void push_behind(node_t * head, int val);
void push_before(node_t ** head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);

#endif
