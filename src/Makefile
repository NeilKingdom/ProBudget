#Header directory
DDIR=include
#Header files
_DEPS=probudget.h
#Path to header files
DEPS=$(patsubst %,$(DDIR)/%,$(_DEPS))
#Library dependencies
LIBS=-lncurses -lm

#Source directory
ODIR=obj
#All object files
_OBJ=probudget.o
#Path to object files
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

#Compiler
CC=gcc
#Compiler options
CFLAGS=-g -Wall -I$(DDIR)

$(ODIR)/%.o: probudget.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS) 

install: $(OBJ)
	$(CC) -o ProBudget $^ $(LIBS) $(CFLAGS) 

.PHONY: clean

clean: 
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
