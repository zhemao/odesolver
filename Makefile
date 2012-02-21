CC=gcc
OPTS=-O2 -Wall

rk4sdtest: odes.o rk4sdtest.c
	$(CC) $(OPTS) rk4sdtest.c odes.o -lm -o rk4sdtest
rk4test: odes.o rk4test.c
	$(CC) $(OPTS) rk4test.c odes.o -lm -o rk4test

odes.o: odes.h odes.c
	$(CC) $(OPTS) -c odes.c
