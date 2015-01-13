# define a compiler
CC = gcc

# define location of library
LIBDIR = ../lib

# define compile time flags
CFLAGS = -Wall -g -I$(IDIR)

# define library needed for compilation
LIBS = -lstatic

# define library linking related flags
LFLAGS = -L../lib

# define source files for program
SRC = main.c

# define object files for program
OBJS = $(SRC:.c=.o)

# define name of execuable
TARGET = staticlib-test

# define library target
LIBTARGET = libstatic.a

# define location of headers
IDIR = ../include

# define variables needed
RM = rm -rf
CD = cd

all: $(TARGET)

$(LIBTARGET):
	$(CD) $(LIBDIR); $(MAKE)

$(TARGET): $(LIBTARGET) $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) $(LIBS)

clean:
	$(RM) $(OBJS) $(TARGET)
	$(CD) $(LIBDIR); $(MAKE) clean
