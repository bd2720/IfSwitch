#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include "ifSwitch.h"
// IF(v,r,b);
#include "if.out"


int main(){
	printf("Running ifSwitch: (ITERS=%llu), (N=%llu)\n", ITERS, N);
	srand(time(0));
	int i, v, mod;
	struct timeval t0, tf; // time (timevals)
	float t; // time (number)
	// test if
	printf("Testing IF...\n");
	gettimeofday(&t0, 0);
	for(i = 0; i < ITERS; i++){
		v = rand() % N;
		IF(v,mod,mod=0);
	}
	gettimeofday(&tf, 0);
	t = TIME(t0,tf);
	printf("If test ran in %f seconds.\n", t);


	return 0;
}
