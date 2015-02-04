# define a compiler
CC = gcc

# define a location for headers
IDIR = ../inc

# define compile time flags
CFLAGS = -Wall -g -I$(IDIR)

# define target for send program
TARGET_SEND = send

# define target for receive process
TARGET_RCV = rcv

# define sources for sender
SRCS_SEND = send.c

# define sources for receiver
SRCS_RCV = rcv.c

# define object files for sender
OBJS_SEND = $(SRCS_SEND:.c=.o)

# define object files for receiver
OBJS_RCV = $(SRCS_RCV:.c=.o)

all: $(TARGET_SEND) $(TARGET_RCV)

$(TARGET_SEND): $(OBJS_SEND)
	$(CC) $(CFLAGS) -o $@ $(OBJS_SEND)

$(TARGET_RCV): $(OBJS_RCV)
	$(CC) $(CFLAGS) -o $@ $(OBJS_RCV)

clean:
	$(RM) $(TARGET_SEND) $(TARGET_RCV) $(OBJS_SEND) $(OBJS_RCV)
