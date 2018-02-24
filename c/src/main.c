#define DEXTREE_N_MAX 6
#include "../lib/neuro/neuro.h"
// https://github.com/troglobit/libicmp
// main
int main(void){
    // init devs
    devs_type* dev0 = malloc( sizeof( devs_type ) ); dev_init( dev0 );
    devs_type* dev1 = malloc( sizeof( devs_type ) ); dev_init( dev1 );
    // init dextree
    dextree_type* dextree = malloc( sizeof( devs_type ) ); dextree_init( dextree );
    // configure devs
    dev0->is_use = true;
    sprintf( dev0->in.iface, "enp3s0" );
    sprintf( dev0->out.iface, "lo" );
    sprintf( dev1->out.iface, "wlp2s0" );
    // configure dextree
    int _w[DEXTREE_N_MAX][DEXTREE_N_MAX] = { {  0,  7,  9,  0,  0, 14 },
                                             {  7,  0, 10, 15,  0,  0 },
                                             {  9, 10,  0, 11,  0,  2 },
                                             {  0, 15, 11,  0,  6,  0 },
                                             {  0,  0,  0,  6,  0,  9 },
                                             { 14,  0,  2,  0,  9,  0 } };
    memcpy( dextree->w, _w, DEXTREE_N_MAX * DEXTREE_N_MAX * sizeof(int) );
    // swap devs
    dev_swap( dev0, dev1 );

    // this code
    printf( "Code me :)\n" );
    printf( "%d\n", sizeof( int ) );
    
    // free memory
    free( dev0 ); dev0 = NULL;
    free( dev1 ); dev1 = NULL;
    free( dextree ); dextree = NULL;
    
    return 0;
}

