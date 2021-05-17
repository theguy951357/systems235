IDIR = ../include
BINDIR = ../bin
CC=gcc
CFLAGS=-I$(IDIR)
LDFLAGS=-lm

ODIR=obj
LDIR =../lib

_DEPS = hellofunc.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $(BINDIR)/$@ $^ $(CFLAGS) $(LDFLAGS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core$(IDIR)/*~

