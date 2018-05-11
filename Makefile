SOURCES =\
main.c\
linked_list.c\

EXEC_NAME = prog
CC = gcc
CCFLAGS = -g -std=c11
OBJECTS = $(SOURCES:.c=.o)

all: $(EXEC_NAME)
	@size --format=Berkeley $(EXEC_NAME)

$(EXEC_NAME): $(OBJECTS)
	$(CC) $(CCFLAGS) -o $(EXEC_NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CCFLAGS) -c  $(SOURCES)
clean:
	rm $(OBJECTS) $(EXEC_NAME)
run: all
	./$(EXEC_NAME)
