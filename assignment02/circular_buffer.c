#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

volatile int volatile buffer[16]; volatile int addhere;
volatile int removehere;
void clearbuffer()
{
addhere = 0; removehere = 0;
for( int i=0; i<16; i++ ) { buffer[i] = 0; }
}
int next( int current )
{
return ( current+1 ) & 15;
}
void addtobuffer( int value )
{
while( next(addhere) == removehere ) {} // Spin waiting for room if ( buffer[addhere] != 0 )
{ printf( "Circular buffer error\n" ); exit(1); }
     buffer[addhere] = value;   //   Add item to buffer
     addhere = next(addhere);   //   Move to next entry
     }         
int removefrombuffer()
{
int value;
while( ( value = buffer[removehere] ) == 0 ){} // Spin until
 buffer[removehere] = 0;    //   Zero out element
removehere = next(removehere);  //   Move to next    entry
return value;                  
}