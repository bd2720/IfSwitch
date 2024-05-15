#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>
#include "ifSwitch.h"
// IF(v,r,b);
#include "if.out"
// SWITCH(v,r,b);
#include "switch.out"

int main(){
	printf("Running ifSwitch: (ITERS=%llu), (N=%llu)\n", ITERS, N);
	srand(time(0));
	int i, v, mod;
	struct timeval t0, tf; // time (timevals)
	float tIf, tSwitch; // time (number)
	// test if
	printf("Testing IF...\n");
	gettimeofday(&t0, 0);
	for(i = 0; i < ITERS; i++){
		v = rand() % N;
		IF(v,mod,mod=0);
	}
	gettimeofday(&tf, 0);
	tIf = TIME(t0,tf);
	printf("If test ran in %f seconds.\n", tIf);
	// test switch
	printf("Testing SWITCH...\n");
	gettimeofday(&t0, 0);
	for(i = 0; i < ITERS; i++){
		v = rand() % N;
		SWITCH(v,mod,mod=0);
	}
	gettimeofday(&tf, 0);
	tSwitch = TIME(t0,tf);
	printf("Switch test ran in %f seconds.\n", tSwitch);
	
	printf("tIf/tSwitch: %f\n", tIf/tSwitch);
	return 0;
}
