# define sender target
TARGET_SEND = send

# define receiver target
TARGET_RCV = rcv

# define location of sources
SRCS = src

# define required variables
CD = cd

all: $(TARGET_SEND) $(TARGET_RCV)

$(TARGET_SEND):
	$(CD) $(SRCS); $(MAKE) $@

$(TARGET_RCV):
	$(CD) $(SRCS); $(MAKE) $@

clean:
	$(CD) $(SRCS); $(MAKE) clean
