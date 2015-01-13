# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -fPIC -Wall -g

# define shared library related flags
LDFLAGS = -shared

# define target for shared library
LIBTARGET = dynamiclibrary

# define target name
LIBTARGET_NAME = libshared.so

# define source files for library
LIBSRC = white.c black.c

# define object files for library
LIBOBJS = $(LIBSRC:.c=.o)

all: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJS)
	$(CC) $(LDFLAGS) -o $(LIBTARGET_NAME) $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS) $(LIBTARGET_NAME)
