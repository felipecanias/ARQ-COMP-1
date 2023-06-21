CC = gcc
CCFLAGS = -o output
LDFLAGS = -lncurses -lcurl -lpthread
SRC = assembly/fantastico.s assembly/choque.s assembly/carrera.s assembly/otro.s assembly/parpadeo.s main.c http.c include/cJSON.c

all: clean output

output:
	$(CC) $(CCFLAGS) $(SRC) $(LDFLAGS)

clean:
	rm -rf *.o output