# define the C compiler
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define the library paths if needed
LFLAGS = -L.

# define directories containing header files
INCLUDES = -I.

# define if any library is needed
LIBS = -lstatic

# define source file of static library
LIBSRC = white.c black.c

# define the source
SRC = main.c

# define object files for static library
LIBOBJS = $(LIBSRC:.c=.o)

# define the object files
OBJS = $(SRC:.c=.o)

# define the output
TARGET = staticlib-test

# define the target name of library
LIBTARGET = libstatic.a

# define extra variables needed
AR = ar crv

all: $(LIBTARGET) $(TARGET)

$(LIBTARGET) : $(LIBOBJS)
	$(AR) $@ $(LIBOBJS)

$(TARGET): $(OBJS) $(LIBTARGET)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

clean:
	rm -rf $(OBJS) $(LIBOBJS) $(LIBTARGET) $(TARGET)
