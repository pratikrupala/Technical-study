# define a compiler
CC = gcc

# define target
TARGET = sharedlib-test

# define library only target
LIBTARGET = dynamiclibrary

# define source directory
SRCDIR = src

# define lirary directory
LIBDIR = lib

# define required variables
CD = cd

all: $(TARGET)

$(TARGET):
	$(CD) $(SRCDIR); $(MAKE)

$(LIBTARGET):
	$(CD) $(LIBDIR); $(MAKE)

clean:
	$(CD) $(SRCDIR); $(MAKE) clean
