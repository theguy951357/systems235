#.PHONY: all say_hello generate clean

#all: say_hello generate

#say_hello:
#	@echo "Hello World"

#generate:
#	@echo "Creating empty text files..."
#	touch file-{1..10}.txt

#clean:
#	@echo "Cleaning up..."
#	rm *.txt

# Usage:
# make    #compile all binary
# make clean  #remove ALL binaries and objects

.PHONY = all clean

CC = gcc     #compiler to use

LINKERFLAG = -lm

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

%: %.o
	@echo "Checking.."
	${CC} ${LINKERFLAG} $< -o $@

%.o: %c
	@echo "Creating object.."
	${CC} -c $<

clean:
	@echo "cleaning up..."
	rm -rvf *.o ${BINS}
