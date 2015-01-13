CC = gcc
CFLAGS = -fPIC -Wall -g
LDFLAGS = -shared
LIBTARGET = dynamiclibrary
LIBTARGET_NAME = libshared.so
LIBSRC = black.c
LIBOBJS = $(LIBSRC:.c=.o)
RM = rm -rf

all: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJS)
	$(CC) $(LDFLAGS) -o $(LIBTARGET_NAME) $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS) $(LIBTARGET_NAME)
