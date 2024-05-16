#include <stdio.h>
#include <string.h>
#include "ifSwitch.h"

char buf[1<<20];

// generate the switch macro:
/* rem = var % n;
   switch(rem){
	case 0:
   		body
	break;
	...
   	case (n-1):
		body
	break;
	default:
		body
   }
*/

int generateSwitch(){
	char *s0 = "#define SWITCH(v,r,b) do{(r)=(v)%";
	int s0_len = strlen(s0);
	// n
	char *s1 = ";switch(r){case 0:(b);break;";
	int s1_len = strlen(s1);
	// s2 or s4
	char *s2 = "case ";
	int s2_len = strlen(s2);
	// i
	char *s3 = ":(b);break;";
	int s3_len = strlen(s3);
	// s2 or s4
	char *s4 = "default:(b);}}while(0)";
	int s4_len = strlen(s4);

	if(N < 2) return -1;
	FILE *f = fopen("switch.out", "w");
	if(!f) return -1;
	char *p = buf; // pointer to start of buf
	strcpy(p, s0);
	p += s0_len;
	char nBuf[12];
	sprintf(nBuf, "%d", N);
	char n_len = strlen(nBuf);
	strcpy(p, nBuf);
	p += n_len;
	strcpy(p, s1);
	p += s1_len;
	
	fwrite(buf, sizeof(char), (long)(p - buf), f);
	p = buf; // reset temp ptr after write
		
	int i, i_len;
	char iBuf[12];
	// be memory-safe, write in chunks
	for(i = 1; i < N-1; i++){
		strcpy(p, s2);
		p += s2_len;
		sprintf(iBuf, "%d", i);
		i_len = strlen(iBuf);
		strcpy(p, iBuf);
		p += i_len;
		strcpy(p, s3);
		p += s3_len;
		
		fwrite(buf, sizeof(char), (long)(p - buf), f);
		p = buf; // reset temp ptr after write
	}
	strcpy(p, s4);
	p += s4_len;
	fwrite(buf, sizeof(char), (long)(p - buf), f);
	fclose(f);
	return 0;
}

int main(){
	return generateSwitch();
}
