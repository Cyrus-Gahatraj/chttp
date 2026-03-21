CC=gcc
CFLAGS=-Iinclude
MAIN=main
SRC_DIR=src
SRCS=$(wildcard $(SRC_DIR)/*.c)
BIN=$(MAIN).out

all: $(MAIN)

$(MAIN): $(SRC_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(BIN) 

clean:
	rm -f $(BIN) 
