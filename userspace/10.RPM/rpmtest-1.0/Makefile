CC = gcc
CFLAGS = -Wall -g
TARGET = rpm-test
INST_DIR = /usr/bin
SRCS = test.c
OBJS = $(SRCS:.c=.o)
CP = cp
RM = rm -rf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

install:
	if( test ! -d $(DESTDIR)$(INST_DIR) ); then mkdir -p $(DESTDIR)$(INST_DIR); fi
	$(CP) $(TARGET) $(DESTDIR)$(INST_DIR)

clean:
	$(RM) $(OBJS) $(TARGET)
