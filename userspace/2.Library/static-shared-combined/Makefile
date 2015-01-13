# define a compiler
CC = gcc

# define target
TARGET = sharedlib-test

# define static library only target
STATIC_LIBTARGET = staticlibrary

# define dynamic library only target
SHARED_LIBTARGET = dynamiclibrary

# define source directory
SRCDIR = src

# define static library directory
STATIC_LIBDIR = static-lib

# define dynamic library directory
SHARED_LIBDIR = shared-lib

# define required variables
CD = cd

all: $(TARGET)

$(TARGET):
	$(CD) $(SRCDIR); $(MAKE)

$(STATIC_LIBTARGET):
	$(CD) $(STATIC_LIBDIR); $(MAKE)

$(SHARED_LIBTARGET):
	$(CD) $(SHARED_LIBDIR); $(MAKE)

clean:
	$(CD) $(SRCDIR); $(MAKE) clean
