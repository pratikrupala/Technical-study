# define compiler flags
CC = gcc

# Provide headers location
IDIR = ../inc

# define compilation flags
CFLAGS = -Wall -g -I$(IDIR)

# provide source for target consumer
CONSUMER_SRC = consumer.c

# provide source for target producer
PRODUCER_SRC = producer.c

# define name of target for consumer
CONSUMER_TARGET = consumer

# define name of target for producer
PRODUCER_TARGET = producer

# define name of objects for consumer
CONSUMER_OBJS = $(CONSUMER_SRC:.c=.o)

# define name of objects for producer
PRODUCER_OBJS = $(PRODUCER_SRC:.c=.o)

# List required variables
RM = rm -rf

all: $(CONSUMER_TARGET) $(PRODUCER_TARGET)

$(CONSUMER_TARGET): $(CONSUMER_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CONSUMER_OBJS)

$(PRODUCER_TARGET): $(PRODUCER_OBJS)
	$(CC) $(CFLAGS) -o $@ $(PRODUCER_OBJS)

clean:
	$(RM) $(PRODUCER_OBJS) $(CONSUMER_OBJS) $(PRODUCER_TARGET) $(CONSUMER_TARGET)
