all: if

ifSwitch: ifSwitch.c ifSwitch.h
	gcc ifSwitch.c -O0 -g -o ifSwitch

if: if.c ifSwitch.h
	gcc if.c -O0 -o if

clean:
	rm if if.out ifSwitch
