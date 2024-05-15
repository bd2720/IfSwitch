all: ifSwitch

ifSwitch: ifSwitch.c ifSwitch.h if.out switch.out
	gcc ifSwitch.c -O0 -o ifSwitch

if.out: if
	./if

switch.out: switch
	./switch

if: if.c ifSwitch.h
	gcc if.c -O0 -o if

switch: switch.c ifSwitch.h
	gcc switch.c -O0 -o switch

clean:
	rm -f if if.out switch switch.out ifSwitch
