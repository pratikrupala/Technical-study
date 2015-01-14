# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define a target
TARGET = threads

# define source files
SRC = threads.c

# define object files
OBJS = $(SRC:.c=.o)

# define library needed
LIBS = -lpthread

# define variables needed
RM = rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LIBS)

clean:
	$(RM) $(OBJS) $(TARGET)
