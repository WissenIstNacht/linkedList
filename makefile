#
# Makefile that builds btest and other helper programs for the CS:APP data lab
# 
#NOTE: if code span several sourcefiles, all must be compiled!

CC = gcc
CFLAGS = -Wall -g

#OUT is the sourcefile's name and the program's name!
#source has the added c sourcefile suffix
OUT = linked_list
SRC = $(OUT).c
HEAD = $(OUT).h

#compiles the linkedlist source/header and the testing program.
prog:  $(SRC) test_linked_list.c $(HEAD)
	$(CC) $(CFLAGS) test_linked_list.c $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
