CCOMP = gcc
CFLAGS = -lm

run: main.o
	$(CCOMP) $(CFLAGS) main.o -o run

main.o: main.c
	$(CCOMP) $(CFLAGS) -c main.c

.PHONY: clean cleanall

clean:
	rm -f run *.o
