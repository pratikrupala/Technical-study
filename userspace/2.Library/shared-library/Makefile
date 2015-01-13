# define a compiler
CC = gcc

# define any compile time flags
CFLAGS = -fPIC -Wall -g

# define flags related to shared library
LDFLAGS = -shared

# define library flags
LFLAGS = -L.

# define extra library flags
EXTRA_LFLAGS = -Wl,-rpath=.

# define if library is needed
LIBS = -lshared

# define source file for test program
SRC = main.c

# difine source files of shared library
LIBSRC = white.c black.c

# define object file for test program
OBJS = main.o

# define object file for library
LIBOBJS = white.o black.o

# define name of executable
TARGET = libshared-test

# define library target
LIBTARGET = dynamiclibrary

# define the name of shared library
LIBTARGET_NAME = libshared.so

# define variables needed
RM = rm -rf

all: $(LIBTARGET) $(TARGET)

$(LIBTARGET): $(LIBOBJS)
	$(CC) $(LDFLAGS) -o $(LIBTARGET_NAME) $(LIBOBJS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(SRC) $(LIBS) $(LFLAGS) $(EXTRA_LFLAGS)

clean:
	$(RM) $(LIBOBJS) $(OBJS) $(LIBTARGET_NAME) $(TARGET)
