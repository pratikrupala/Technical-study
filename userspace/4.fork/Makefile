# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define a target
TARGET = fork

# define source files
SRC = fork.c

# define object files
OBJS = $(SRC:.c=.o)

# define variables needed
RM = rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	$(RM) $(OBJS) $(TARGET)
