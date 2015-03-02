SHELL = /bin/sh

CC = gcc
CFLAGS = -Wall -Werror -Wpedantic -g -std=c99

BUILDDIR = bin
SRCDIR = src
OBJDIR = bin
INCLUDE = -Iincludes

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

LIB =

all: main

main: $(OBJ)
	$(CC) -o $(BUILDDIR)/final $^ $(LIB) $(INCLUDE)

$(BUILDDIR)/%.c: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDE)

clean:
	rm -rf $(BUILDDIR)/final

mrproper:
	rm -rf $(BUILDDIR)/*
