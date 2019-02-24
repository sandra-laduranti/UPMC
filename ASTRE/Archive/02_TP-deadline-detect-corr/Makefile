CC=gcc
CFLAGS=-I. -DDEBUG #
DEPS = threads_ports.h threads_dispatch.h functions.h types.h wdlib.h Makefile
OBJ = main.o functions.o threads_ports.o threads_dispatch.o wdlib.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	gcc -o fault_detection_app $^ $(CFLAGS) -lpthread -lrt

clean:
	rm -f *.o core *~ fault_detection_app
