CC = gcc
CFLAGS ?= -Wall
CFLAGS += -c -std=c99 
SOURCES = xkbmstate.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=xkbmstate

# need X11 lib
CFLAGS     += `pkg-config --cflags x11`
LDFLAGS    += `pkg-config --libs x11`

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm *.o
