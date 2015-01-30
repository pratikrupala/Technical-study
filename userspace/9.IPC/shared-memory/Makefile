# define a target for consumer
TARGET_CONSUMER = consumer

# define a target for producer
TARGET_PRODUCER = producer

# List the location of source files
SRC = src

# define required varibles
CD = cd
MAKE = make

all: $(TARGET_CONSUMER) $(TARGET_PRODUCER)
	$(CD) $(SRC); $(MAKE)

$(TARGET_CONSUMER):
	$(CD) $(SRC); $(MAKE) $@

$(TARGET_PRODUCER):
	$(CD) $(SRC); $(MAKE) $@

clean:
	$(CD) $(SRC); $(MAKE) clean
