# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define a target
TARGET = mysync

# define a new target
NEW_TARGET = mysync-nolock

# define source files
SRC = mysync.c

# define sources for new target
NEW_SRC = mysync-nolock.c

# define object files
OBJS = $(SRC:.c=.o)

# define object files for new souces
NEW_OBJS = $(NEW_SRC:.c=.o)

# define library needed
LIBS = -lpthread

# define variables needed
RM = rm -rf

all: $(TARGET) $(NEW_TARGET)

$(NEW_TARGET): $(NEW_OBJS)
	$(CC) $(CFLAGS) -o $@ $(NEW_SRC) $(LIBS)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LIBS)

clean:
	$(RM) $(OBJS) $(NEW_OBJS) $(TARGET) $(NEW_TARGET)
