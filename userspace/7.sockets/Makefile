# define a compiler
CC = gcc

# define compile time flags
CFLAGS = -Wall -g

# define a server target
STARGET = server

# define a client target
CTARGET = client

# define source files
SERVER_SRC = server.c

# define client files
CLIENT_SRC = client.c

# define object files server objects
SERVER_OBJS = $(SERVER_SRC:.c=.o)

# define object files client objects
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)

# define variables needed
RM = rm -rf

all: $(STARGET) $(CTARGET)

$(STARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC)

$(CTARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRC)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(STARGET) $(CTARGET)
