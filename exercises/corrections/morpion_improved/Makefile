SHELL = /bin/sh

CC = gcc
CFLAGS = -W -Wall -Wpedantic -Wextra -std=c99

BUILDDIR = bin
SRCDIR = src
OBJDIR = bin
INCLUDE = includes

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIB = 

all: main

main: $(OBJ)
	$(CC) -o $(BUILDDIR)/final $^ $(LIB) $(INCLUDE)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

clean:
	rm -rf $(BUILDDIR)/final

mrproper:
	rm -rf $(BUILDDIR)/*
