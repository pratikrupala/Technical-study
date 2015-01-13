# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define library directory
LIBDIR = lib

# define source dir
SRCDIR = src

# define target name
TARGET = staticlib-test

# define library target
LIBTARGET = staticlibrary

all: $(TARGET)

$(LIBTARGET):
	cd $(LIBDIR); $(MAKE)

$(TARGET):
	cd $(SRCDIR); $(MAKE)

clean:
	cd $(SRCDIR); $(MAKE) clean
