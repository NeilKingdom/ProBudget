#Compiler
CC=gcc
#Compiler options
CFLAGS=-g -Wall -I.
#Header files
DEPS=NULL
#Library dependencies
LIBS=-lncurses -lm

#Source directory
ODIR=src
#All object files
_OBJ=ProBudget.o
#Path to object files
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(ODIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS) 

install: $(OBJ) 
	$(CC) -o ProBudget $^ $(LIBS) $(CFLAGS) 

.PHONY: clean

clean: 
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
