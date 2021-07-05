CC = gcc
OBJS  = CheckNumbers.o general.o main.o sudoku.o tickets.o
EXEC = prog
DEBUG= -g
CFLAGS = -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@ -lm
CheckNumbers.o: CheckNumbers.c CheckNumbers.h
general.o: general.c general.h
main.o: main.c CheckNumbers.h sudoku.h tickets.h
sudoku.o: sudoku.c sudoku.h
tickets.o: tickets.c tickets.h

clean:
	rm -f *.o
