CC = gcc
IDIR = ../inc
CFLAGS = -Wall -g -I$(IDIR)
TARGET = libtest
SRC = main.c
STATIC_LIBDIR = ../static-lib
SHARED_LIBDIR = ../shared-lib
STATICLIB = staticlibrary
SHAREDLIB = sharedlibrary
USERLIBDIR = /usr/lib
LIBDEP = libshared.so
LFLAGS = -L../static-lib -L../shared-lib
LIBS = -lstatic -lshared
EXTRA_LFLAGS = -Wl,-rpath=/usr/lib
CD = cd
CP = cp

all: $(TARGET)

$(STATICLIB):
	$(CD) $(STATIC_LIBDIR); $(MAKE)

$(SHAREDLIB):
	$(CD) $(SHARED_LIBDIR); $(MAKE)

$(TARGET): $(STATICLIB) $(SHAREDLIB) $(IDIR)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LFLAGS) $(LIBS) $(EXTRA_LFLAGS)
	$(CP) $(SHARED_LIBDIR)/$(LIBDEP) $(USERLIBDIR)

clean:
	$(RM) $(TARGET) $(USERLIBDIR)/$(LIBDEP)
	$(CD) $(STATIC_LIBDIR); $(MAKE) clean
	$(CD) $(SHARED_LIBDIR); $(MAKE) clean
