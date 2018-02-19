// neuro.h
#ifndef NEURO_H
#define NEURO_H

static struct variables {
    int ping_ms;
    int bw_tx;
    int bw_rx;
    int type;       // master || slave channel
    unsigned char mac_addr[6];
};

typedef struct node {
        int val;
        struct variables eth0;
        struct variables eth1;
        struct variables ppp;
        struct node * next;
} node_t;

void print_list(node_t * head);
void push_behind(node_t * head, int val);
void push_before(node_t ** head, int val);
int pop(node_t ** head);
int remove_last(node_t * head);

#endif
