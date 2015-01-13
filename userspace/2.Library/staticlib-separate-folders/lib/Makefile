# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define source files for library
LIBSRC = white.c black.c

# define object files for library
LIBOBJS = $(LIBSRC:.c=.o)

# define target name for library
LIBTARGET = staticlibrary

# define library name
LIBTARGET_NAME = libstatic.a

# define variables needed
AR = ar crv
RM = rm -rf

all: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJS)
	$(AR) $(LIBTARGET_NAME) $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS) $(LIBTARGET_NAME)
