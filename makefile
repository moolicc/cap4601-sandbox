# Define required macros here
SHELL = /bin/sh

OBJS =  main.o
CFLAG = -Wall -g
CC = gcc
INCLUDE =
LIBS = -lm

hello:${OBJ}
   ${CC} ${CFLAGS} ${INCLUDES} -o $@ ${OBJS} ${LIBS}

clean:
   -rm -f *.o core *.core

.cpp.o:
   ${CC} ${CFLAGS} ${INCLUDES} -c $<