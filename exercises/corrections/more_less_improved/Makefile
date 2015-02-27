SHELL = /bin/sh

CC = gcc
CFLAGS = -W -Wall -Wpedantic -Wextra -std=c99
BUILDDIR = bin
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.c)
OBJDIR = bin
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
LIB = 
INCLUDE = -Iincludes

all: main

main: $(OBJ)
	$(CC) -o $(BUILDDIR)/final $^ $(LIB) $(INCLUDE)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

clean:
	rm -rf $(BUILDDIR)/final

mrproper:
	rm -rf $(BUILDDIR)/*
