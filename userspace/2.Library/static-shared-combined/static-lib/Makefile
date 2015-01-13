CC = gcc
CFLAGS = -Wall -g
LIBTARGET = staticlibrary
LIBTARGET_NAME = libstatic.a
LIBSRC = white.c
LIBOBJS = $(LIBSRC:.c=.o)
AR = ar crv
RM = rm -rf

all: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJS)
	$(AR) $(LIBTARGET_NAME) $(LIBOBJS)

clean:
	$(RM) $(LIBOBJS) $(LIBTARGET_NAME)
