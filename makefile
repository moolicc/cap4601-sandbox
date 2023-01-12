# Define required macros here
SHELL = /bin/sh

OBJS =  main.o
CFLAG = -Wall -g
CC = gcc
LIBS = -lm

hello:${OBJ}
   ${CC} ${CFLAGS} -o $@ ${OBJS} ${LIBS}

clean:
   -rm -f *.o core *.core

.cpp.o:
   ${CC} ${CFLAGS} -c $<