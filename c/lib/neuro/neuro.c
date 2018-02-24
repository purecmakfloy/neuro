// neuro.c
#include "neuro.h"
// init device
void dev_init( devs_type* dev ) {
    if ( dev == NULL ) {
        printf( "No memory\n" );
        exit( -1 );
    }
    memset( dev, 0, sizeof( devs_type ) );
}
// apply changes devices
void dev_change_apply( devs_type* dev ){
    dev->swap->is_use = ! dev->is_use;
    sprintf( dev->swap->in.iface, "%s", dev->in.iface );
}
// swaping devices
void dev_swap( devs_type* dev0, devs_type* dev1 ){
    dev0->swap = dev1;
    dev1->swap = dev0;
    dev_change_apply( dev0 );
}

void dextree_init( dextree_type* dextree ){
    if ( dextree == NULL ) {
        printf( "No memory\n" );
        exit( -1 );
    }
    for ( int i = 0; i < DEXTREE_N_MAX; i++ ){
        for ( int j = 0; j < DEXTREE_N_MAX; j++ ){
            dextree->w[i][j] = 1000;
            dextree->D[i][j] = 0;
        }
        dextree->visited[i] = false;
    }
}