// neuro.h
#ifndef NEURO_H
#define NEURO_H

// libs attache
#ifndef STDIO_H
    #define STDIO_H
    #include <stdio.h>
#endif

#ifndef STDBOOL_H
    #define STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef STDLIB_H
    #define STDLIB_H
    #include <stdlib.h>
#endif

#ifndef STRING_H
    #define STRINGH
    #include <string.h>
#endif

typedef struct devs_struct {
    bool is_use;                    // Flag is use channel
    int total_rate[5];              // The last 5 load values ​​per channel per second
    unsigned char coef;             // Coefficient of use channel {0..100} %
    int max_rate[1500];             // The dependence of max speed on the length
    int rate[5][1500];              // of the packet (table data)
    struct addr_struct {
        char iface[10];             // Iface nane, ex.: eth0
        struct ip_strcut {          // IPv4 address
            unsigned char src[4];   //
            unsigned char dst[4];   //
        } ip;                       //______________
        struct mac_struct {         // MAC address
            unsigned char src[6];   //
            unsigned char dst[6];   //
        } mac;                      //______________
    } in, out;
    struct devs_struct* swap;       // Link for switching traffic to another channel
} devs_type;

// Алгоритм Дейкстры
#ifndef DEXTREE_N_MAX
    #define DEXTREE_N_MAX 10
#endif
typedef struct dextree_struct {
    int w[DEXTREE_N_MAX][DEXTREE_N_MAX]; // Матрица путей (хранит вес ребер)
    int D[DEXTREE_N_MAX][DEXTREE_N_MAX]; // Массив минимальных путей
    bool visited[DEXTREE_N_MAX];         // Массив посещенных вершин
} dextree_type;

// function attache
void dev_init( devs_type* dev );
void dev_change_apply( devs_type* dev );
void dev_swap( devs_type* dev0, devs_type* dev1 );
void dextree_init( dextree_type* dextree );

#endif
