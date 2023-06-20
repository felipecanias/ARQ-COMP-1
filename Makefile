CC = gcc
CCFLAGS = -o output
LDFLAGS = -lncurses -lcurl -lpthread
SRC = main.c http.c include/cJSON.c

all: clean output

output:
	$(CC) $(CCFLAGS) $(SRC) $(LDFLAGS)

clean:
	rm -rf *.o output