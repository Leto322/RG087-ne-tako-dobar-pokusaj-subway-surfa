PROGRAM = runner
MAIN = main.c
MAIN_H = main.h
MOVEMENT = movement.c
MOVEMENT_H = movement.h
DRAWING = drawing.c
DRAWING_H = drawing.h
CC = gcc
CFLAGS  = -g -std=c99 -Wall -Wextra -I/usr/X11R6/include -I/usr/pkg/include
LDFLAGS = -L/usr/X11R6/lib -L/usr/pkg/lib
LDLIBS  = -lglut -lGLU -lGL -lm

$(PROGRAM): main.o movement.o drawing.o
		$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

main.o: $(MAIN) $(MAIN_H)
		$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

movement.o: $(MOVEMENT) $(MOVEMENT_H) $(MAIN_H)
		$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

drawing.o: $(DRAWING) $(DRAWING_H) $(MAIN_H)
		$(CC) $(CFLAGS) -c -o $@ $< $(LDLIBS)

.PHONY: clean

clean:
		-rm *.o $(PROGRAM)
