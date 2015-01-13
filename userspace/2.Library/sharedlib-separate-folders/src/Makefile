# define a compiler
CC = gcc

# define location of header files
IDIR = ../inc

# define a location of library
LIBDIR = ../lib

# define location for lirary installation
USERLIBDIR = /usr/lib

# define compile time flags
CFLAGS = -Wall -g -I$(IDIR)

# define library relared fags
LFLAGS = -L../lib

# define library related extra flags
EXTRA_LFALGS = -Wl,-rpath=/usr/lib

# define a library to link
LIBS = -lshared

# define name of executable
TARGET = sharedlib-test

# define library dependency
LIBDEP = libshared.so

# define source files
SRC = main.c

# define object files
OBJS = $(SRC:.c=.o)

# define required variables
RM = rm -rf
CD = cd
CP = cp

all: $(TARGET)

$(LIBDEP):
	$(CD) $(LIBDIR); $(MAKE)

$(TARGET): $(LIBDEP) $(IDIR)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LFLAGS) $(LIBS) $(EXTRA_LFALGS)
	$(CP) $(LIBDIR)/$(LIBDEP) $(USERLIBDIR)

clean:
	$(RM) $(OBJS) $(TARGET) $(USERLIBDIR)/$(LIBDEP)
	$(CD) $(LIBDIR); $(MAKE) clean
