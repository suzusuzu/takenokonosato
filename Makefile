CC=gcc
CFLAGS=-O

UNAME = ${shell uname}

ifeq ($(UNAME),Linux)
CURSES = -lncursesw
endif

ifeq ($(UNAME),Darwin)
CURSES = -lncurses
endif

takenoko: takenoko.c
	$(CC) $(CFLAGS) -o takenoko takenoko.c $(CURSES)
