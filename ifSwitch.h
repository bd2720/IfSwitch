#ifndef IFSWITCH_H
#define IFSWITCH_H

#include <sys/time.h>

// number of loop iterations for each test
#define ITERS 1000000

// number of if and/or else statements, or switch cases.
#define N 1000

// compute elapsed time between 2 timevals
#define TIME(t1, t2) ((t2).tv_sec-(t1).tv_sec)+(((t2).tv_usec-(t1).tv_usec)/1e6)
#endif
